import solve_py
import os
import sys


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __is_palindrome(string: str) -> bool:
        length: int = len(string)
        for i in range(0, length // 2, 1):
            if string[i] != string[length - i - 1]:
                return False
        return True

    @staticmethod
    def __ztos_base(z: int, str_base: str) -> str:
        result: str = ""
        base: int = len(str_base)
        z_copy: int = z
        if z_copy < 0:
            z_copy *= -1
        while z_copy > 0:
            base_pos = z_copy % base
            result = str_base[base_pos:base_pos + 1] + result
            z_copy //= base
        if z < 0:
            result = "-" + result
        return result

    @staticmethod
    def __solve(limit: int) -> None:
        solution: int = 0
        for i in range(1, limit, 1):
            i_base_dec: str = Solution.__ztos_base(i, "0123456789")
            i_base_bin: str = Solution.__ztos_base(i, "01")
            if Solution.__is_palindrome(i_base_dec) is True and \
               Solution.__is_palindrome(i_base_bin) is True:
                solution += i
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
