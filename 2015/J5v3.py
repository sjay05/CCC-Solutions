# --- IMPORTS ---
from sys import stdin

input = stdin.readline

def readInt():
    return int(input())

N = readInt()
K = readInt()
MAX = N/K+1

# n = pieces of pie; k = people in line
def piDay(n, k, m):
    if n == 0 or k == 0:
        return 1

    t = 0
    for i in range(m, MAX):
        t += piDay(n-i, k-1, i)
    return t

print piDay(N, K, 1)

