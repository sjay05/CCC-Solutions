# Clean version of 2019 J4 
from sys import stdin

input = stdin.readline


# ---- START OF Templates ----
def gen(val, length):
    return [val] * length


def p2d(matrix):
    for line in matrix:
        sline = ""
        for i in line:
            sline += str(i)
            sline += " "
        print sline


# ---- END OF Templates ----

if __name__ == '__main__':
    seq = input()
    grid = [[1, 2],
            [3, 4]]
    for op in seq:
        if op == "H":
            grid[0][0], grid[1][0] = grid[1][0], grid[0][0]
            grid[0][1], grid[1][1] = grid[1][1], grid[0][1]
        elif op == "V":
            grid[0][0], grid[0][1] = grid[0][1], grid[0][0]
            grid[1][0], grid[1][1] = grid[1][1], grid[1][0]

    p2d(grid)
