import utils


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __solve(n: int) -> None:
        solution: int = 1
        for i in range(1, n, 1):
            solution = utils.lcm(solution, i + 1)
        print(f"Solution for {n}: {solution}")

    def execute(self) -> None:
        n: int = 0
        if self.__argc < 2:
            try:
                n = int(input())
            except Exception:
                pass
            Solution.__solve(n)
            return
        for i in range(1, self.__argc, 1):
            try:
                n = int(self.__argv[i])
            except Exception:
                pass
            Solution.__solve(n)
