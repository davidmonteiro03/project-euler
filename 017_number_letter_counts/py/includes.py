import solve_py
import os
import sys


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __show_number(n: int) -> int:
        d: list[int] = [n // 100, (n % 100) // 10, n % 10]
        main_str: list[str] = ["zero", "one", "two", "three",
                               "four", "five", "six", "seven",
                               "eight", "nine"]
        teen_str: list[str] = ["ten", "eleven", "twelve", "thirteen",
                               "fourteen", "fifteen", "sixteen",
                               "seventeen", "eighteen", "nineteen"]
        ty_str: list[str] = [None, "ten", "twenty", "thirty", "forty",
                             "fifty", "sixty", "seventy", "eighty", "ninety"]
        tmp: str = ""
        if d[0] > 0:
            tmp += f"{main_str[d[0]]}hundred"
        if d[0] > 0 and d[1] + d[2] > 0:
            tmp += "and"
        if d[1] > 0:
            tmp += teen_str[d[2]] if d[1] == 1 else ty_str[d[1]]
        if d[2] > 0 and d[1] != 1:
            tmp += main_str[d[2]]
        return len(tmp)

    @staticmethod
    def __analyse_number(n: int) -> int:
        solution: int = 0
        if n > 999:
            solution += Solution.__analyse_number(n // 1000)
            solution += Solution.__analyse_number(n % 1000)
        else:
            solution = Solution.__show_number(n)
        return solution

    @staticmethod
    def __solve(start: int, end: int) -> None:
        solution: int = 0
        for i in range(start, end + 1, 1):
            if i == 0:
                solution += len("zero")
            else:
                solution += Solution.__analyse_number(i)
            if i >= 1000:
                solution += len("thousand")
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
            print("{0}: error: '{1}' '{2}' are not both integers.".format(
                self.__argv[0], self.__argv[1], self.__argv[2]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_DATAERR
            return
        Solution.__solve(start, end)
