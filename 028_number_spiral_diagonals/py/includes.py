import solve_py
import os
import sys
import math


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv
        self.__spiral = None
        self.__m = 0
        self.__n = 0

    def __fillSpiral(self) -> None:
        if len(self.__spiral) < 1 or self.__m == 0 or self.__n == 0 or self.__m % 2 == 0 or self.__n % 2 == 0 or self.__m != self.__n:
            return
        x: int = self.__m // 2
        y: int = self.__n // 2
        direction: int = 0
        count: int = 1
        steps: int = 1
        self.__spiral[x][y] = count
        count += 1
        while count <= self.__m * self.__n:
            for _ in range(0, 2, 1):
                for __ in range(0, steps, 1):
                    if count > self.__m * self.__n:
                        break
                    if direction == 0:
                        y += 1
                    elif direction == 1:
                        x += 1
                    elif direction == 2:
                        y -= 1
                    else:
                        x -= 1
                    self.__spiral[x][y] = count
                    count += 1
                direction = (direction + 1) % 4
            steps += 1

    @staticmethod
    def __solve(spiral: list[list[int]], m: int, n: int) -> None:
        solution: int = 0
        if len(spiral) < 1 or m == 0 or n == 0 or m % 2 == 0 or n % 2 == 0 or m != n:
            return
        for i in range(0, m, 1):
            for j in range(0, n, 1):
                solution += spiral[i][j] * (i == j or i == n - j - 1)
        print("Solution for {0} by {1}: {2}".format(
            m, n, solution
        ), file=sys.stdout)

    def execute(self) -> None:
        if len(self.__spiral) < 1 or solve_py.g_exit_status != os.EX_OK:
            return
        Solution.__solve(self.__spiral, self.__m, self.__n)

    def fill(self) -> None:
        if solve_py.g_exit_status != os.EX_OK:
            return
        if self.__argc != 3:
            print("usage: {0} <m> <n>".format(
                self.__argv[0]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_USAGE
            return
        m: int = 0
        n: int = 0
        try:
            m = int(self.__argv[1])
            n = int(self.__argv[2])
        except Exception:
            print("{0}: error: '{1}' and '{2}' are not both integers.".format(
                self.__argv[0], self.__argv[1], self.__argv[2]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_DATAERR
            return
        if m <= 0 or n <= 0 or m % 2 == 0 or n % 2 == 0 or m != n:
            return
        self.__m = m
        self.__n = n
        self.__spiral = [[0 for _ in range(self.__n)] for __ in range(self.__m)]
        self.__fillSpiral()

