from judge import AutoGrader
from pathlib import Path


def main():
    # 初始化 AutoGrader 實例
    ca1 = AutoGrader(
        "../../zip",
        "../../result_ca1",
        "./meta.json",
    )

#     ca1.exc_judge()
    ca1.exc_single_judge(Path("../../zip/b12505042#_李俊霖 (LEE, CHUN-LIN)_185406_6218701_CA1B12505042.zip"))

if __name__ == "__main__":
    main()


