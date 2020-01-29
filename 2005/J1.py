# --- INPUT HANDLING ---
from sys import stdin

input = stdin.readline
# --- INPUT HANDLING ---

# --- START OF TEMPLATE ----
def gen(val, length):
    return [val] * length

def p2d(matrix):
    for line in matrix:
        print line

def readStr():
    return input()

def readInt():
    return int(input())
# ---- END OF TEMPLATE ---


