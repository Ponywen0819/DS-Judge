from judge import AutoGrader
from pathlib import Path


def main():
    # 初始化 AutoGrader 實例
    ca4 = AutoGrader(
        "./zip",
        "./result",
        "./meta.json",

    )

    ca4.unzip_all_submissions()

    # ca4.exc_judge(verbose=True)
    ca4.exc_single_judge(Path("zip/b11505054#_曾慶玹 (CHING-XUAN, TSENG)_149626_6508866_CA4B11505054.rar"))


if __name__ == "__main__":
    main()
