import solve_py
import os
import sys


EX__BASE = 64


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv
        self.__names = list[str]()

    def __fill_names(self, filename: str) -> None:
        if len(filename) < 1 or solve_py.g_exit_status != os.EX_OK:
            return
        try:
            with open(filename, "r") as f:
                words: list[str] = f.read().strip().split(',')
                for w in words:
                    name = w.removeprefix("\"").removesuffix("\"")
                    if len(name) > 0:
                        self.__names.append(name)
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
        self.__fill_names(self.__argv[1])

    @staticmethod
    def __get_letter_code(c: int) -> int:
        if c >= ord('A') and c <= ord('Z'):
            return c - 65 + 1
        if c >= ord('a') and c <= ord('z'):
            return c - 97 + 1
        return 0

    @staticmethod
    def __get_name_score(name: str, pos: int) -> int:
        if len(name) < 1 or pos < 0:
            return 0
        result: int = 0
        for i in range(0, len(name), 1):
            result += Solution.__get_letter_code(ord(name[i]))
        result *= pos + 1
        return result

    @staticmethod
    def __solve(names: list[str], filename: str) -> None:
        solution: int = 0
        if len(names) < 1 or len(filename) < 1:
            return
        names.sort()
        for i in range(0, len(names), 1):
            solution += Solution.__get_name_score(names[i], i)
        print("Solution for \"{0}\": {1}".format(
            filename, solution
        ), file=sys.stdout)

    def execute(self) -> None:
        if len(self.__names) < 1 or solve_py.g_exit_status != os.EX_OK:
            return
        Solution.__solve(self.__names, self.__argv[1])
