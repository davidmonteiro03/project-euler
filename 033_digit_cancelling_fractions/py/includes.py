import solve_py
import os
import sys
from fractions import Fraction


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __remove_common(a: str, b: str) -> tuple[str, str]:
        a_list: list = list(a)
        b_list: list = list(b)
        i: int = 0
        while i < len(a_list):
            if a_list[i] in b_list:
                find_a_pos: int = a_list.index(a_list[i])
                find_b_pos: int = b_list.index(a_list[i])
                a_list.pop(find_a_pos)
                b_list.pop(find_b_pos)
                i = 0
            else:
                i += 1
        return "".join(a_list), "".join(b_list)

    @staticmethod
    def __compute_ac(numerator: int, denominator: int) -> tuple[int, int]:
        numerator_str: str = str(numerator)
        denominator_str: str = str(denominator)
        numerator_str, denominator_str = \
            Solution.__remove_common(numerator_str, denominator_str)
        try:
            return int(numerator_str), int(denominator_str)
        except Exception:
            return 0, 0

    @staticmethod
    def __solve(n: int) -> None:
        solution: int = 0
        product: Fraction = Fraction(1, 1)
        for numerator in range(1, pow(10, n), 1):
            for denominator in range(numerator + 1, pow(10, n), 1):
                if numerator < 10 or denominator < 10:
                    continue
                if numerator % 10 == 0 and denominator % 10 == 0:
                    continue
                ac: tuple[int, int] = \
                    Solution.__compute_ac(numerator, denominator)
                if numerator == ac[0] and denominator == ac[1]:
                    continue
                if denominator == 0 or ac[1] == 0:
                    continue
                q0: Fraction = Fraction(numerator, denominator)
                q1: Fraction = Fraction(ac[0], ac[1])
                if q0 != q1:
                    continue
                product *= q1
        solution = product.denominator
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
