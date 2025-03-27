class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def find_next_prime(n: int) -> int:
        if n <= 1:
            return Solution.find_next_prime(n + 1)
        if n <= 3:
            return n
        if n % 2 == 0 or n % 3 == 0:
            return Solution.find_next_prime(n + 1)
        i: int = 5
        while i * i <= n and i * i > 0:
            if n % i == 0 or n % (i + 2) == 0:
                return Solution.find_next_prime(n + 1)
            i += 6
        return n

    @staticmethod
    def __solve(n: int) -> None:
        solution: int = Solution.find_next_prime(0)
        tmp_n: int = n - 1
        while tmp_n > 0:
            solution = Solution.find_next_prime(solution + 1)
            tmp_n -= 1
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
