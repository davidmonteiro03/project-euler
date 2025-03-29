import solve_py
import os
import sys


EX__BASE = 64


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv
        self.__grid = [[0 for _ in range(20)] for __ in range(20)]
        self.__m = len(self.__grid)
        self.__n = len(self.__grid[0])

    def __fill_grid(self, filename: str) -> None:
        if len(filename) < 1 or solve_py.g_exit_status != os.EX_OK:
            solve_py.g_exit_status = EX__BASE
            return
        try:
            with open(filename, "r") as f:
                words = map(str, f.read().split())
                for i in range(0, self.__m, 1):
                    for j in range(0, self.__n, 1):
                        try:
                            self.__grid[i][j] = int(next(words))
                        except Exception:
                            solve_py.g_exit_status = EX__BASE
                            return
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
        self.__fill_grid(self.__argv[1])

    def __compute_max_horiz_prod(self, length: int) -> int:
        if length == 0:
            return 0
        result: int = 0
        for i in range(0, self.__m - length + 1, 1):
            for j in range(0, self.__n - length + 1, 1):
                prod: int = 1
                for k in range(0, length, 1):
                    prod *= self.__grid[i][j + k]
                result = max(result, prod)
        return result

    def __compute_max_vert_prod(self, length: int) -> int:
        if length == 0:
            return 0
        result: int = 0
        for i in range(0, self.__m - length + 1, 1):
            for j in range(0, self.__n - length + 1, 1):
                prod: int = 1
                for k in range(0, length, 1):
                    prod *= self.__grid[i + k][j]
                result = max(result, prod)
        return result

    def __compute_max_diag_prod(self, length: int) -> int:
        if length == 0:
            return 0
        result: int = 0
        for i in range(0, self.__m - length + 1, 1):
            for j in range(0, self.__n - length + 1, 1):
                prod: int = 1
                for k in range(0, length, 1):
                    prod *= self.__grid[i + k][j + k]
                result = max(result, prod)
        return result

    def __compute_max_rdiag_prod(self, length: int) -> int:
        if length == 0:
            return 0
        result: int = 0
        for i in range(0, self.__m - length + 1, 1):
            for j in range(0, self.__n - length + 1, 1):
                prod: int = 1
                for k in range(0, length, 1):
                    prod *= self.__grid[i + k][j + length - k - 1]
                result = max(result, prod)
        return result

    def execute(self) -> None:
        if solve_py.g_exit_status != os.EX_OK:
            return
        result: int = 0
        max_horiz_prod: int = self.__compute_max_horiz_prod(4)
        max_vert_prod: int = self.__compute_max_vert_prod(4)
        max_diag_prod: int = self.__compute_max_diag_prod(4)
        max_rdiag_prod: int = self.__compute_max_rdiag_prod(4)
        result = max(result, max_horiz_prod)
        result = max(result, max_vert_prod)
        result = max(result, max_diag_prod)
        result = max(result, max_rdiag_prod)
        print("Solution for \"{0}\": {1}".format(
            self.__argv[1], result
        ), file=sys.stdout)
