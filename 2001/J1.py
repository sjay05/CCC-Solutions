"""
author: sjay05
"""
from sys import stdin

input = stdin.readline

H = int(input())
arr = []

for i in range(1, H+1, 2):
    s = (i*"*") + ((2*H-2*i)*" ") + (i*"*")
    if i < H-1: arr.append([s])
    print s

arr.reverse()
for line in arr:
    print line[0]
