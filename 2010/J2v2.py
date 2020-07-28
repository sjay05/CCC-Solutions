"""
author: sjay05
"""
# --- IMPORTS ---
from sys import stdin

input = stdin.readline

def readInt():
    return int(input())

# --- CONSTANTS ---
a = readInt()
b = readInt()
c = readInt()
d = readInt()
s = readInt()
sumNikky = 0
sumBryon = 0

if __name__ == '__main__':
    toDo = 0
    SUM = 0
    while True:
        if SUM >= s:
            break
        # FORWARD
        if toDo == 0:
            sumNikky += a
            sumBryon += c
            toDo = 1
            if a > c:
                SUM += a
            else:
                SUM += c
        # BACKWARD
        else:
            sumNikky -= b
            sumBryon -= d
            toDo = 0
            if b > d:
                SUM += b
            else:
                SUM += d

    if sumNikky > sumBryon:
        print "Nikky"
    elif sumNikky < sumBryon:
        print "Byron"
    else:
        print "Tied"
