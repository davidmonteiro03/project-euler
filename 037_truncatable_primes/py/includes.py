import solve_py
import os
import sys


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __is_prime(n: int) -> bool:
        if n <= 1:
            return False
        i: int = 2
        while i * i <= n:
            if n % i == 0:
                return False
            i += 1
        return True

    @staticmethod
    def __num_len(n: int) -> int:
        string: str = str(n)
        return len(string)

    @staticmethod
    def __is_truncable_prime(n: int) -> bool:
        if n < 10 or Solution.__is_prime(n) is False:
            return False
        n_len: int = Solution.__num_len(n)
        for i in range(0, n_len, 1):
            n_pow: int = 10 ** (n_len - i)
            if Solution.__is_prime(n % n_pow) is False:
                return False
        n_len: int = Solution.__num_len(n)
        for i in range(0, n_len, 1):
            n_pow: int = 10 ** i
            if Solution.__is_prime(n // n_pow) is False:
                return False
        return True

    @staticmethod
    def __solve(n: int) -> None:
        solution: int = 0
        count: int = 0
        i: int = 1
        while count < n:
            if Solution.__is_truncable_prime(i) is True:
                count += 1
                solution += i
            i += 1
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
