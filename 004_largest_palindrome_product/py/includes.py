class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __get_limit(n: int) -> int:
        limit: int = 1
        tmp_n: int = n
        while tmp_n > 1:
            limit *= 10
            tmp_n -= 1
        return limit

    @staticmethod
    def __update_solution(solution: int, i: int, j: int) -> None:
        buf: str = str(i * j)
        length: int = len(buf)
        palindrome: bool = True
        for k in range(0, length // 2, 1):
            if buf[k] != buf[length - k - 1]:
                palindrome = False
                break
        if palindrome is True and i * j > solution:
            return i * j
        return solution

    @staticmethod
    def __solve(n: int) -> None:
        solution: int = 0
        i: int = Solution.__get_limit(n)
        limit: int = i * 10
        while i < limit:
            for j in range(i, limit, 1):
                solution = Solution.__update_solution(solution, i, j)
            i += 1
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
