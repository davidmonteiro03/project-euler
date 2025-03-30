import solve_py
import os
import sys


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def find_next_prime(n: int) -> int:
        if n <= 1:
            return Solution.find_next_prime(n + 1)
        if n <= 3:
            return n
        if n % 2 == 0 or n % 3 == 0:
            return Solution.find_next_prime(n + 1)
        i: int = 5
        while i * i <= n and i * i > 0:
            if n % i == 0 or n % (i + 2) == 0:
                return Solution.find_next_prime(n + 1)
            i += 6
        return n

    @staticmethod
    def __solve(n: int) -> None:
        solution: int = 0
        next_prime: int = Solution.find_next_prime(0)
        while next_prime < n:
            solution += next_prime
            next_prime = Solution.find_next_prime(next_prime + 1)
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
