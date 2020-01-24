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
text = ""
length = 0

if __name__ == '__main__':
    length = readInt()
    for i in range(length):
        stext = readStr()
        text += stext

    Tt_count = 0
    Ss_count = 0
    for char in text:
        if char == "s" or char == "S":
            Ss_count += 1
        if char == "t" or char == "T":
            Tt_count += 1

    # --- COMPARISONS ---
    if Ss_count == Tt_count:
        print "French"
    elif Ss_count>Tt_count:
        print "French"
    elif Tt_count>Ss_count:
        print "English"
