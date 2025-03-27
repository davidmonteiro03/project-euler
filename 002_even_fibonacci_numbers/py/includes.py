import solve_py
import os
import sys


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __solve(n: int) -> None:
        solution: int = 0
        first: int = 1
        second: int = 1
        next: int = first + second
        while first < n:
            solution += first * (first % 2 == 0)
            first = second
            second = next
            next = first + second
        print("Solution for {0}: {1}".format(
            n, solution
        ), file=sys.stdout)

    def execute(self) -> None:
        if self.__argc < 2:
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
