from includes import Solution
import sys


def main():
    solution = Solution(len(sys.argv), sys.argv)
    solution.execute()


if __name__ == "__main__":
    main()
