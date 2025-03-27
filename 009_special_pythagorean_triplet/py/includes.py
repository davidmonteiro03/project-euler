class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __find_pythagorean_triplet(n: int) -> int:
        for a in range(1, n, 1):
            for b in range(a + 1, n, 1):
                for c in range(b + 1, n, 1):
                    if a * a + b * b == c * c and a + b + c == n:
                        return a * b * c
        return 0

    @staticmethod
    def __solve(n: int) -> None:
        solution: int = Solution.__find_pythagorean_triplet(n)
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
