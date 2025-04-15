import solve_py
import os
import sys
import math


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __next_permutation(set: str) -> str:
        tmp = list(set)
        size: int = len(tmp)
        if size <= 1:
            return
        i: int = size - 2
        while i >= 0 and tmp[i] >= tmp[i + 1]:
            i -= 1
        if i < 0:
            return
        j: int = size - 1
        while tmp[j] <= tmp[i]:
            j -= 1
        tmp[i], tmp[j] = tmp[j], tmp[i]
        start: int = i + 1
        end: int = size - 1
        while start < end:
            tmp[start], tmp[end] = tmp[end], tmp[start]
            start += 1
            end -= 1
        return "".join(tmp)

    @staticmethod
    def __solve(n: int, pos: int) -> None:
        solution: str = ""
        for i in range(0, n, 1):
            solution += str(i)
        limit: int = math.factorial(n)
        i: int = 0
        while i < limit and i < pos - 1:
            solution = Solution.__next_permutation(solution)
            i += 1
        print("Solution for {0} at {1}: {2}".format(
            n, pos, solution
        ), file=sys.stdout)

    def execute(self) -> None:
        if self.__argc != 3:
            print("usage: {0} <n> <pos>".format(
                self.__argv[0]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_USAGE
            return
        try:
            n = int(self.__argv[1])
            pos = int(self.__argv[2])
        except Exception:
            print("{0}: error: '{1}' and '{2}' are not in a valid \
date format.".format(
                self.__argv[0], self.__argv[1], self.__argv[2]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_DATAERR
            return
        Solution.__solve(n, pos)
