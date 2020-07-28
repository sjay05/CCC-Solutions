"""
author: sjay05
"""
# --- IMPORTS ---
from sys import stdin

input = stdin.readline

def readInt():
    return int(input())

adj = {i:[] for i in range(10)}

def rec(n):
    total = 1
    for i in adj[n]:
        # We are adding (+1) because that element
        # can be picked by itself or be automatically picked
        # when one of it's parent node's get picked
        total = total * (rec(i) + 1)

    return total

if __name__ == '__main__':
    n = readInt()
    # Create an adj array to highlight
    # who invited who.
    for i in range(1, n):
        a = readInt()
        adj[a].append(i)

    print rec(n)
