import solve_py
import os
import sys


EX__BASE = 64


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv
        self.__nums = None

    def __fill_nums(self, filename: str) -> None:
        if len(filename) < 1 or solve_py.g_exit_status != os.EX_OK:
            solve_py.g_exit_status = EX__BASE
            return
        try:
            with open(filename, "r") as f:
                self.__nums = list(map(int, f.read().split()))
        except Exception:
            solve_py.g_exit_status = EX__BASE
            return

    def fill(self) -> None:
        if solve_py.g_exit_status != os.EX_OK:
            return
        if self.__argc != 2:
            print("usage: {0} <filename>".format(
                self.__argv[0]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_USAGE
            return
        self.__fill_nums(self.__argv[1])

    def __extract_first_10_digits_from_sum(self) -> int:
        big_sum: int = 0
        for i in range(0, len(self.__nums), 1):
            tmp: int = int(self.__nums[i])
            big_sum += tmp
        sum_str: str = str(big_sum)
        result_str: str = sum_str[0:10]
        result: int = int(result_str)
        return result

    def execute(self) -> None:
        if solve_py.g_exit_status != os.EX_OK:
            return
        result: int = self.__extract_first_10_digits_from_sum()
        print("Solution for \"{0}\": {1}".format(
            self.__argv[1], result
        ), file=sys.stdout)
