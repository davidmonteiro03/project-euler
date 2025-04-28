import solve_py
import os
import sys


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __check_pandigital(n: int, lim: int, ds: str) -> int:
        result: int = 0
        ps: list[int] = []
        for a in range(1, lim, 1):
            for b in range(1, lim, 1):
                prod: int = a * b
                r: str = str(a) + str(b) + str(prod)
                if len(r) != n:
                    continue
                r = "".join(sorted(r))
                if r != ds:
                    continue
                if prod in ps:
                    continue
                ps.append(prod)
                result += prod
        return result

    @staticmethod
    def __solve(n: int) -> None:
        solution: int = 0
        if n < 1 or n > 9:
            return
        limit: int = pow(10, n // 2)
        digits: str = ""
        for i in range(0, n, 1):
            digits += str(i + 1)
        solution = Solution.__check_pandigital(n, limit, digits)
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
