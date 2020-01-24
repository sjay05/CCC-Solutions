"""
Contest Coding Template - Python 2.7
Can be accesed with live shortcut "template"
"""

# --- INPUT HANDLING ---
from sys import stdin

input = stdin.readline


# --- INPUT HANDLING ---

# --- START OF Templates ----
def build(val, length):
    return [val] * length


def p2d(matrix):
    for line in matrix:
        print line


def readStr():
    return input()


def readInt():
    return int(input())


def readStrArr():
    arr = input().split()
    return arr


def readIntArr():
    arr = input().split()
    arr = [int(i) for i in arr]
    return arr


def pContents(x):
    for i in x:
        print i


# ---- END OF Templates ---

# --- CONSTANTS ----

if __name__ == '__main__':
    print 0
