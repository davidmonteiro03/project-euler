class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __solve(n: int) -> None:
        solution: int = 0
        tmp_n: int = n
        while tmp_n % 2 == 0:
            solution = 2
            tmp_n //= 2
        factor: int = 3
        while factor * factor <= tmp_n:
            while tmp_n % factor == 0:
                solution = factor
                tmp_n //= factor
            factor += 2
        if tmp_n > 2:
            solution = tmp_n
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
