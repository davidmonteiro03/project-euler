import solve_py
import includes
import sys


def main():
    solution = includes.Solution(len(sys.argv), sys.argv)
    solution.execute()
    sys.exit(solve_py.g_exit_status)


if __name__ == "__main__":
    main()
