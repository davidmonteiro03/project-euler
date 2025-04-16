import solve_py
import os
import sys


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __decimal_period(remainder: int, divisor: int) -> str:
        storage: list[int] = [-1] * divisor
        decimal: str = ""
        i: int = 0
        while remainder != 0 and storage[remainder] == -1:
            storage[remainder] = i
            remainder *= 10
            decimal += str(remainder // divisor)
            remainder %= divisor
            i += 1
        if remainder == 0:
            return decimal
        return decimal[remainder:]

    @staticmethod
    def __reciprocal_cycle(dividend: int, divisor: int) -> int:
        if divisor == 0:
            return 0
        remainder: int = dividend % divisor
        if remainder != 0:
            period: str = Solution.__decimal_period(remainder, divisor)
            if len(period) < 1:
                return 0
            return len(period)
        return 0

    @staticmethod
    def __solve(n: int) -> None:
        solution: int = 0
        max_len: int = 0
        for i in range(1, n, 1):
            tmp_len: int = Solution.__reciprocal_cycle(1, i)
            if tmp_len > max_len:
                solution = i
                max_len = tmp_len
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
