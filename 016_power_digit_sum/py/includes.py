import solve_py
import os
import sys


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __solve(base: int, exp: int) -> None:
        solution: int = 0
        pow_value: int = pow(base, exp)
        pow_str: str = str(pow_value)
        for i in range(0, len(pow_str), 1):
            solution += int(pow_str[i])
        print("Solution for [{0}, {1}]: {2}".format(
            base, exp, solution
        ), file=sys.stdout)

    def execute(self) -> None:
        if self.__argc != 3:
            print("usage: {0} <base> <exp>".format(
                self.__argv[0]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_USAGE
            return
        base: int = 0
        exp: int = 0
        try:
            base = int(self.__argv[1])
            exp = int(self.__argv[2])
        except Exception:
            print("{0}: error: '{1}' '{2}' are not both integers.".format(
                self.__argv[0], self.__argv[1], self.__argv[2]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_DATAERR
            return
        Solution.__solve(base, exp)
