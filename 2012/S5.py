"""
author: sjay05
"""
from sys import stdin

input = stdin.readline

R, C = map(int, input().split())
cats = []

def rec(r, c):
    if (r, c) == (R,C): # == brother
        return 1
    if (r, c) in cats:
        return 0
    if r > R or c > C:
        return 0

    return rec(r+1, c) + rec(r, c+1)

def tabulate():
    grid = [[0 for i in range(C+1)] for i in range(R+1)]
    grid[1][1] = 1
    for i in range(1, R+1):
        for j in range(1, C+1):
            if (i,j) not in cats:
                    grid[i][j] += grid[i-1][j] + grid[i][j-1]

    print grid[R][C]

if __name__ == '__main__':
    k = int(input())
    for i in range(k):
        x, y = map(int, input().split())
        cats.append((x, y))

    tabulate()
