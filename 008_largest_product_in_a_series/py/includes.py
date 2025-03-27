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
        for i in range(0, len(solve_py._1000_DIGIT_NUMBER) - n, 1):
            prod: int = 1
            for j in range(i, i + n, 1):
                prod *= int(solve_py._1000_DIGIT_NUMBER[j])
            solution = max(solution, prod)
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
