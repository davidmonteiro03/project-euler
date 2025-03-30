import solve_py
import os
import sys


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
        print("Solution for {0}: {1}".format(
            n, solution
        ), file=sys.stdout)

    def execute(self) -> None:
        if self.__argc != 2:
            print("usage: {0} <n>".format(
                self.__argv[0]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_USAGE
            return
        n: int = 0
        try:
            n = int(self.__argv[1])
        except Exception:
            print("{0}: error: '{1}' is not an integer.".format(
                self.__argv[0], self.__argv[1]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_DATAERR
            return
        Solution.__solve(n)
