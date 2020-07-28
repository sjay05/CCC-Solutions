"""
author: sjay05
"""
from sys import stdin
from collections import Counter

input = stdin.readline

Y = int(input()) + 1


def check(n):
    d = Counter(n)
    for i in d.keys():
        if d[i]>1:
            return False

    return True


if __name__ == '__main__':
    while True:
        if check(str(Y)):
            print Y
            break
        else:
            Y += 1
