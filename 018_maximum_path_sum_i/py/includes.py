import solve_py
import os
import sys


EX__BASE = 64


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv
        self.__triangle = list[list[int]]()
        self.__n_lines = 0

    def __triangle_alloc(self) -> None:
        self.__triangle = [None] * self.__n_lines
        for i in range(0, len(self.__triangle), 1):
            self.__triangle[i] = [None] * (i + 1)

    def __triangle_fill(self, filename: str) -> None:
        if len(filename) < 1 or solve_py.g_exit_status != os.EX_OK:
            solve_py.g_exit_status = EX__BASE
            return
        try:
            with open(filename, "r") as f:
                words = map(str, f.read().split())
                for i in range(0, self.__n_lines, 1):
                    for j in range(0, i + 1, 1):
                        try:
                            self.__triangle[i][j] = int(next(words))
                        except Exception:
                            solve_py.g_exit_status = EX__BASE
                            return
        except Exception:
            solve_py.g_exit_status = EX__BASE
            return

    def fill(self) -> None:
        if solve_py.g_exit_status != os.EX_OK:
            return
        if self.__argc != 3:
            print("usage: {0} <filename> <num_lines>".format(
                self.__argv[0]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_USAGE
            return
        try:
            self.__n_lines = int(self.__argv[2])
        except Exception:
            print("{0}: error: '{1}' is not an integer.".format(
                self.__argv[0], self.__argv[2]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_USAGE
            return
        self.__triangle_alloc()
        self.__triangle_fill(self.__argv[1])

    def __solve_recursive(self, i: int, j: int, row: int, col: int) -> int:
        if j == col:
            return 0
        if i == row - 1:
            return self.__triangle[i][j]
        return self.__triangle[i][j] + \
            max(self.__solve_recursive(i + 1, j, row, col),
                self.__solve_recursive(i + 1, j + 1, row, col))

    def execute(self) -> None:
        result: int = self.__solve_recursive(0, 0,
                                             self.__n_lines, self.__n_lines)
        print("Solution for [\"{0}\", {1}]: {2}".format(
            self.__argv[1], self.__argv[2], result
        ), file=sys.stdout)
