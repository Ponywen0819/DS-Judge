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
    # ca1.exc_single_judge(Path("../../zip/b11505039#_王律衡 (LU-HENG WANG)_138700_6238927_CA1B11505039.zip"))

if __name__ == "__main__":
    main()


