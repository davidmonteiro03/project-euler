import solve_py
import os
import sys


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
