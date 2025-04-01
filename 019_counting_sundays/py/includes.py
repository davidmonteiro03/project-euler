import solve_py
import os
import sys
import datetime


class Solution:
    def __init__(self, argc: int, argv: list[str]):
        self.__argc = argc
        self.__argv = argv

    @staticmethod
    def __count_first_sundays_from_to(sd: datetime.datetime,
                                      ed: datetime.datetime) -> int:
        count: int = 0
        i: datetime.datetime = sd
        limit: datetime.datetime = ed
        while i <= ed:
            count += (i.day == 1 and i.weekday() == 6)
            i += datetime.timedelta(days=1)
        return count

    @staticmethod
    def __solve(sd: datetime.datetime, ed: datetime.datetime) -> None:
        solution: int = Solution.__count_first_sundays_from_to(sd, ed)
        print("Solution for [{0} - {1}]: {2}".format(
            sd.strftime("%d/%m/%Y"), ed.strftime("%d/%m/%Y"), solution
        ), file=sys.stdout)

    def execute(self) -> None:
        if self.__argc != 3:
            print("usage: {0} <start_date> <end_date>".format(
                self.__argv[0]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_USAGE
            return
        try:
            sd = datetime.datetime.strptime(self.__argv[1], "%d %b %Y")
            ed = datetime.datetime.strptime(self.__argv[2], "%d %b %Y")
        except Exception:
            print("{0}: error: '{1}' and '{2}' are not in a valid \
date format.".format(
                self.__argv[0], self.__argv[1], self.__argv[2]
            ), file=sys.stderr)
            solve_py.g_exit_status = os.EX_DATAERR
            return
        Solution.__solve(sd, ed)
