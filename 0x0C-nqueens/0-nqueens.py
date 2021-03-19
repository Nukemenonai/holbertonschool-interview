#!/usr/bin/python3
"""n queens algorithm with  backtracking """
import sys


class NQueen:
    """ Class for solving N Queen Problem """

    def __init__(self, n):
        """ Global Variables """
        self.n = n
        self.x = [0 for i in range(n + 1)]
        self.res = []

    def place(self, k, i):
        """ Check if k Queen can be placed in i column
        or if the are attacking queens in row or diagonal
        """

        # j checks from 1 to k - 1 (Up to previous queen)
        for j in range(1, k):
            # There is already a queen in column
            # or a queen in same diagonal
            if self.x[j] == i or \
               abs(self.x[j] - i) == abs(j - k):
                return 0
        return 1

    def solve(self, k):
        """ Tries to place every queen in the board
        Args:
        k: starting queen from which to evaluate (should be 1)
        """
        # i goes from column 1 to column n (1st column is 1st index)
        for i in range(1, self.n + 1):
            if self.place(k, i):
                # Queen can be placed in i column
                self.x[k] = i
                if k == self.n:
                    # Placed all Queens
                    solution = []
                    for i in range(1, self.n + 1):
                        solution.append([i - 1, self.x[i] - 1])
                    self.res.append(solution)
                else:
                    # Need to place more Queens
                    self.solve(k + 1)
        return self.res


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

entry = sys.argv[1]

try:
    n = int(entry)
except ValueError:
    print("N must be a number")
    sys.exit(1)

if n < 4:
    print("N must be at least 4")
    sys.exit(1)

board = NQueen(n)
res = board.solve(1)

for i in res:
    print(i)
