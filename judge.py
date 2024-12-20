import os
import shutil
import subprocess
import json
from dataclasses import dataclass
from typing import List
from pathlib import Path
import zipfile
import math
import re
from enum import Enum
from concurrent.futures import ProcessPoolExecutor, as_completed


class JudgeStatus(Enum):
    CE = "CE",
    CS = "CS",
    RE = "RE",
    AC = "AC",
    WA = "WA",


@dataclass
class TestSet:
    input: str
    output: str


@dataclass
class TestGroup:
    main_file: Path
    test_sets: List[TestSet]
    total_score: int


@dataclass
class TestMeta:
    judge_files: List[str]
    test_group: List[TestGroup]


@dataclass
class TestRes:
    correct_ans: str
    output_ans: str


@dataclass
class JudgeResult:
    status: JudgeStatus
    correct_ratio: float
    max_score: float
    scaled_score: float
    test_status: List[TestRes]


@dataclass
class TestResult:
    judges: List[JudgeResult]
    score: float


class AutoGrader:
    def __init__(self, submissions_dir, results_dir, meta_file: str, temp_dir="./temp", unzip_dir='./unzip',
                 compiler="g++"):
        self.submissions_dir = Path(submissions_dir).resolve()
        self.temp_dir = Path(temp_dir).resolve()
        self.results_dir = Path(results_dir).resolve()
        self.unzip_dir = Path(unzip_dir).resolve()

        self.compiler = compiler

        self.judge_files: List[str] = []
        self.test_group: List[TestGroup] = []
        self.pattern = re.compile(r'^.*CA\d[A-Za-z]\d{8}(?:-\d)?\.(zip|rar)$', re.IGNORECASE)

        # 確保暫存和結果資料夾存在
        self._check_dir_exists()

        if not os.path.exists(self.temp_dir):
            raise ValueError(f'temp dir {self.temp_dir} does not exist')

        self._set_test_meta(Path(meta_file))

    def copy_submission(self, student_id: str):
        """
        複製學生提交的特定檔案到暫存資料夾。
        :param student_id: 學生學號
        """

        source = self.unzip_dir / Path(student_id)
        for file_name in self.judge_files:

            source_file = source / file_name
            destination = self.temp_dir / file_name
            if source_file.exists():
                shutil.copy(source_file, destination)
                print(f"Copied {source_file} to {destination}")
            else:
                print(f"Warning: {source_file} does not exist.")

    def judge_submission(self, student_id: str):
        """
        處理單一學生的批改
        :param student_id:
        :return: 批改結果
        """
        res = {}

        for test_group in self.test_group:

            test_name = test_group.main_file.stem
            judge_result = JudgeResult(status=JudgeStatus.CS, correct_ratio=0.0,
                                       max_score=test_group.total_score, scaled_score=0.0, test_status=[])
            test_file_path = self.temp_dir / test_group.main_file
            is_compile_success = self._compile_file(test_file_path)

            if not is_compile_success:
                judge_result.status = JudgeStatus.CE
                res[test_name] = judge_result
                continue

            test_res = []
            program_path = self.temp_dir / test_name
            for test_set in test_group.test_sets:
                input_data = test_set.input
                run_res = self._run_program(program_path, input_data)
                if run_res is None:
                    judge_result.status = JudgeStatus.RE
                    break
                test_res.append(TestRes(correct_ans=test_set.output, output_ans=run_res))
            if judge_result.status == JudgeStatus.RE:
                res[test_name] = judge_result
                continue

            os.remove(program_path)

            correct_count = 0
            for test_ in test_res:
                if test_.correct_ans == test_.output_ans:
                    correct_count += 1
            correct_ratio = correct_count / len(test_res)
            judge_result.correct_ratio = correct_ratio
            judge_result.scaled_score = math.floor(judge_result.max_score * correct_ratio)
            judge_result.test_status = test_res

            res[test_name] = judge_result

        self._remove_judge_files()
        return res

    def unzip_all_submissions(self):
        """
        解壓縮所有學生提交的壓縮擋
        """
        submission_list = self._get_zip_files()
        for submission_file in submission_list:
            self._unzip_submission(submission_file)

    def exc_single_judge(self, target_dir: Path):
        self._remove_judge_files()
        student_id = target_dir.stem[:9]
        self.copy_submission(student_id)
        single_res = self.judge_submission(student_id)
        final_score = 0
        for test_name in single_res.keys():
            final_score += single_res[test_name].scaled_score

        self.dump_judge_results(single_res, self.results_dir / f'{student_id}.json')
        print(final_score)
        return final_score

    def exc_judge(self, verbose: bool = False):
        """
        執行批改
        """
        try:
            submission_list = self._get_zip_files()
            judge_res = {}
            for submission_file in submission_list:
                judge_res[submission_file.stem[:9]] = self.exc_single_judge(submission_file)
            with open(self.results_dir / 'result.json', 'w') as f:
                json.dump(judge_res, f)
        finally:
            if not verbose:
                self._clean_up()
            print("Finished")

    def _unzip_submission(self, submission_zip: Path):
        """
        解壓縮學生提交的壓縮擋道指定資料夾
        :param submission_zip: 學生提交壓縮檔所在位置
        """
        destination_name = Path(submission_zip.stem[:9])
        destination = self.unzip_dir / destination_name
        destination.mkdir(parents=True, exist_ok=True)

        file_type = submission_zip.suffix

        if file_type == '.zip':
            with zipfile.ZipFile(submission_zip, 'r') as f:
                f.extractall(destination)

        elif file_type == '.rar':
            command = ['rar', 'x', '-y', os.path.abspath(submission_zip), "."]
            subprocess.run(command, cwd=destination)
        else:
            raise ValueError(f'Unsupported file type: {file_type}')

    def _get_zip_files(self):
        """
        搜尋指定資料夾內符合固定命名格式的 .zip 或 .rar 檔案。
        :return: 符合條件的檔案列表
        """
        if not self.submissions_dir.is_dir():
            raise NotADirectoryError(f"{self.submissions_dir} 不是一個有效的資料夾。")

        # 使用 glob 模式搜尋所有 .zip 和 .rar 檔案
        zip_files = self.submissions_dir.glob('*.zip')
        rar_files = self.submissions_dir.glob('*.rar')

        # 過濾符合命名格式的檔案
        submission_files = [f for f in zip_files if self.pattern.match(f.name)] + \
                           [f for f in rar_files if self.pattern.match(f.name)]

        return submission_files

    @staticmethod
    def _run_program(program: Path, input_data: str):
        try:
            result = subprocess.run(
                [program],  # 可執行檔案的路徑
                input=input_data,  # 傳遞給程式的標準輸入
                capture_output=True,  # 捕捉標準輸出和標準錯誤
                text=True,  # 以文字模式處理輸入和輸出
                check=True,  # 如果程式返回碼非零，拋出 CalledProcessError
                timeout=20
            )
        except subprocess.CalledProcessError as e:
            print(f"程式執行失敗，返回碼: {e.returncode}")
            print(f"標準錯誤訊息: {e.stderr}")
            return None
        except Exception as e:
            print("程式執行失敗，未知錯誤")
            return None
        # 返回標準輸出
        return result.stdout

    def _compile_file(self, file_name: Path):
        output_path = self.temp_dir / file_name.stem
        command = [self.compiler, file_name, '-o', output_path]
        try:
            subprocess.run(command, check=True, timeout=20, capture_output=True, text=True, )
        except subprocess.CalledProcessError as e:
            # 處理程式執行失敗的情況
            print(f"程式執行失敗，返回碼: {e.returncode}")
            print(f"標準錯誤訊息: {e.stderr}")
            return False
        return True

    def _remove_judge_files(self):
        for judge_file in self.judge_files:
            destination = self.temp_dir / judge_file
            if destination.exists():
                os.remove(destination)
                print(f"Removed {judge_file}")

    def _set_test_meta(self, meta_file: Path):
        """
        取得指定的設定檔案
        :param meta_file: 設定檔案位置
        """
        with open(meta_file, 'r') as f:
            data = json.load(f)

            self.judge_files = data.get('judge_files', [])
            test_groups_data = data.get('test_groups', [])

            test_groups = []
            for tg in test_groups_data:
                total = tg.get('total', 0)
                main_file = Path(tg.get('main_file'))
                sets_data = tg.get('sets', [])
                sets = [TestSet(input=ts.get('input'), output=ts.get('output')) for ts in sets_data]
                test_group = TestGroup(total_score=total, main_file=main_file, test_sets=sets)
                test_groups.append(test_group)

            for test_group in test_groups:
                source_file = meta_file.with_name(test_group.main_file.name)
                destination = self.temp_dir / test_group.main_file
                if source_file.exists():
                    shutil.copy(source_file, destination)
                    print(f"Copied {source_file} to {destination}")

            self.test_group = test_groups

    def _check_dir_exists(self):
        # 確保所有目錄存在
        self.submissions_dir.mkdir(parents=True, exist_ok=True)
        self.temp_dir.mkdir(parents=True, exist_ok=True)
        self.results_dir.mkdir(parents=True, exist_ok=True)
        self.unzip_dir.mkdir(parents=True, exist_ok=True)

    def _clean_up(self):
        shutil.rmtree(self.temp_dir)
        shutil.rmtree(self.unzip_dir)

    @staticmethod
    def dump_judge_results(res: dict[str, JudgeResult], file: Path):
        output = {}

        for k in res.keys():
            input = res[k]
            output[k] = {
                "status": input.status.name,
                "scaled_score": input.scaled_score,
                "test_status": [{
                    "output_ans": s.output_ans,
                    "correct_ans": s.correct_ans
                } for s in input.test_status],
                "max_score": input.max_score,
                "correct_ratio": input.correct_ratio
            }

        with open(file, 'w') as f:
            json.dump(output, f)
