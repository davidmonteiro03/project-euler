import solve_py
import os
import sys
import copy


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __is_prime(n: int) -> bool:
        if n <= 1:
            return False
        i: int = 2
        while i * i <= n:
            if n % i == 0:
                return False
            i += 1
        return True

    @staticmethod
    def __solve(limit: int) -> None:
        solution: int = 0
        i: list[int] = [0] * 3
        o: list[int] = [-limit] * 3
        i[0] = -limit + 1
        while i[0] < limit:
            i[1] = -limit
            while i[1] <= limit:
                i[2] = 0
                while True:
                    if not Solution.__is_prime(i[2] * i[2] +
                                               i[0] * i[2] +
                                               i[1]):
                        break
                    i[2] += 1
                if i[2] > o[2]:
                    o = copy.copy(i)
                i[1] += 1
            i[0] += 1
        solution = o[0] * o[1]
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
