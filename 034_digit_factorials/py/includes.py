import solve_py
import os
import sys


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __solve(limit: int) -> None:
        solution: int = 0
        i: int = 10
        while i <= limit and i <= 100000:
            i_str: str = str(i)
            i_copy: int = i
            f_sum: int = 0
            for k in range(0, len(i_str), 1):
                fac: int = 1
                j: int = int(i_str[k])
                while j > 1:
                    fac *= j
                    j -= 1
                f_sum += fac
            if i_copy == f_sum:
                solution += i_copy
            i += 1
        print("Solution for {0}: {1}".format(
            limit, solution
        ), file=sys.stdout)

    def execute(self) -> None:
        if self.__argc != 2:
            print("usage: {0} <limit>".format(
                self.__argv[0]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_USAGE
            return
        limit: int = 0
        try:
            limit = int(self.__argv[1])
        except Exception:
            print("{0}: error: '{1}' is not an integer.".format(
                self.__argv[0], self.__argv[1]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_DATAERR
            return
        Solution.__solve(limit)
