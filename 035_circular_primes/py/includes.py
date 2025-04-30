import solve_py
import os
import sys


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
    def __rotate_str(s: str) -> str:
        if len(s) < 2:
            return s
        tmp: list = list(s)
        first = tmp[0]
        tmp.pop(0)
        tmp.append(first)
        return "".join(tmp)

    @staticmethod
    def __check_circular_prime(n: int) -> bool:
        n_str: str = str(n)
        for k in range(0, len(n_str), 1):
            tmp_n: int = int(n_str)
            if Solution.__is_prime(tmp_n) is False:
                return False
            n_str = Solution.__rotate_str(n_str)
        return True

    @staticmethod
    def __solve(limit: int) -> None:
        solution: int = 0
        for i in range(1, limit, 1):
            solution += Solution.__check_circular_prime(i)
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
