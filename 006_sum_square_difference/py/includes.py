class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __solve(n: int) -> None:
        default_sum: int = n * (n + 1) // 2
        sum_of_squares: int = (n * (n + 1) * (2 * n + 1)) // 6
        square_of_sum: int = default_sum * default_sum
        solution: int = square_of_sum - sum_of_squares
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
