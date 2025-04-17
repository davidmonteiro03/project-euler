import solve_py
import os
import sys


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __count_recursive(coins: list[int], n: int, sum: int) -> int:
        if sum == 0:
            return 1
        if sum < 0 or n == 0:
            return 0
        return Solution.__count_recursive(coins, n, sum - coins[n - 1]) + \
            Solution.__count_recursive(coins, n - 1, sum)

    @staticmethod
    def __solve(sum: int) -> None:
        coins: list[int] = [1, 2, 5, 10, 20, 50, 100, 200]
        solution: int = Solution.__count_recursive(coins, len(coins), sum)
        print("Solution for {0}: {1}".format(
            sum, solution
        ), file=sys.stdout)

    def execute(self) -> None:
        if self.__argc != 2:
            print("usage: {0} <sum>".format(
                self.__argv[0]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_USAGE
            return
        sum: int = 0
        try:
            sum = int(self.__argv[1])
        except Exception:
            print("{0}: error: '{1}' is not an integer.".format(
                self.__argv[0], self.__argv[1]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_DATAERR
            return
        Solution.__solve(sum)
