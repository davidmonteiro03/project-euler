import solve_py
import os
import sys


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __collatz_sequence_length(n: int) -> int:
        result: int = 0
        while n > 1:
            n = n / 2 if n % 2 == 0 else 3 * n + 1
            result += 1
        return result

    @staticmethod
    def __solve(n: int) -> None:
        solution: int = 0
        terms_max: int = 0
        for tmp in range(1, n, 1):
            number_of_terms: int = Solution.__collatz_sequence_length(tmp)
            if number_of_terms > terms_max:
                terms_max = number_of_terms
                solution = tmp
        print("Solution for {0}: {1}".format(
            n, solution
        ), file=sys.stdout)

    def execute(self) -> None:
        if self.__argc < 2:
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
