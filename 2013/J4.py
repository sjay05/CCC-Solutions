"""
author: sjay05
"""
from sys import stdin

input = stdin.readline

T = int(input())
C = int(input())
aa = []

if __name__ == '__main__':
    for i in range(C):
        aa.append(int(input()))
    aa.sort()
    count, t = 0, T
    for c in aa:
        if t - c < 0:
            print count
            break
        else:
            t -= c
            count += 1
