import solve_py
import os
import sys


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __sum_divisors(n: int) -> int:
        result: int = 1
        i: int = 2
        while i * i <= n:
            if n % i == 0:
                result += i
                if i != n // i:
                    result += n // i
            i += 1
        return result

    @staticmethod
    def __is_abundant(n: int) -> bool:
        return Solution.__sum_divisors(n) > n

    @staticmethod
    def __is_sum_of_abundants(n: int) -> bool:
        for i in range(12, n // 2 + 1, 1):
            if Solution.__is_abundant(i) and Solution.__is_abundant(n - i):
                return True
        return False

    @staticmethod
    def __solve(n: int) -> None:
        solution: int = 0
        for i in range(1, n + 1, 1):
            if not Solution.__is_sum_of_abundants(i):
                solution += i
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
