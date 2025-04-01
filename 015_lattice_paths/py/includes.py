import solve_py
import os
import sys
import math


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __solve(k: int, n: int) -> None:
        solution: int = 0
        solution = int(math.factorial(k + n) /
                       (math.factorial(k) * math.factorial(n)))
        print("Solution for [{0}, {1}]: {2}".format(
            k, n, solution
        ), file=sys.stdout)

    def execute(self) -> None:
        if self.__argc != 3:
            print("usage: {0} <k> <n>".format(
                self.__argv[0]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_USAGE
            return
        k: int = 0
        n: int = 0
        try:
            k = int(self.__argv[1])
            n = int(self.__argv[2])
        except Exception:
            print("{0}: error: '{1}' '{2}' are not both integers.".format(
                self.__argv[0], self.__argv[1], self.__argv[2]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_DATAERR
            return
        Solution.__solve(k, n)
