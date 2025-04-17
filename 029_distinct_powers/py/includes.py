import solve_py
import os
import sys


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __solve(start: int, end: int) -> None:
        solution: int = 0
        powers: list[int] = []
        for a in range(start, end + 1, 1):
            for b in range(start, end + 1, 1):
                powers.append(a ** b)
        powers.sort()
        solution = len(powers)
        for i in range(0, len(powers) - 1, 1):
            if powers[i] == powers[i + 1]:
                solution -= 1
        print("Solution for [{0}, {1}]: {2}".format(
            start, end, solution
        ), file=sys.stdout)

    def execute(self) -> None:
        if self.__argc != 3:
            print("usage: {0} <start> <end>".format(
                self.__argv[0]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_USAGE
            return
        start: int = 0
        end: int = 0
        try:
            start = int(self.__argv[1])
            end = int(self.__argv[2])
        except Exception:
            print("{0}: error: '{1}' and '{2} are not both integers.".format(
                self.__argv[0], self.__argv[1], self.__argv[2]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_DATAERR
            return
        Solution.__solve(start, end)
