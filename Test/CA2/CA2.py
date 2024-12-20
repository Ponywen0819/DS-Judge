from judge import AutoGrader
from pathlib import Path


def main():
    # 初始化 AutoGrader 實例
    ca1 = AutoGrader(
        "./zip",
        "./result",
        "./meta.json",
    )

    ca1.exc_judge()
    # ca1.exc_single_judge(Path("./zip/b10505054#_曾廷綸_106573_6286303_CA2.zip"))

if __name__ == "__main__":
    main()


