from judge import AutoGrader
from pathlib import Path


def main():
    # 初始化 AutoGrader 實例
    ca3 = AutoGrader(
        "./zip",
        "./result",
        "./meta.json",

    )

    ca3.unzip_all_submissions()

    # ca3.exc_judge(verbose=True)
    ca3.exc_single_judge(Path("zip/b10505054#_曾廷綸_106573_6334856_CA3B10505054.zip"))


if __name__ == "__main__":
    main()
