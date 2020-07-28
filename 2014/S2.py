"""
author: sjay05
"""
from sys import stdin
input = stdin.readline

N = int(input())
l1 = input().split()
l2 = input().split()
prt = {}

if __name__ == '__main__':
    s = True
    for i in range(len(l1)):
        p1 = l1[i]
        p2 = l2[i]
        if p1 in prt.keys():
            if prt[p1] != p2:
                s = False
                break
        if p2 in prt.keys():
            if prt[p2] != p1:
                s = False
                break
        if p1 == p2:
            s = False
            break
        if p1 not in prt.keys(): prt[p1] = p2
        if p2 not in prt.keys(): prt[p2] = p1

    if not s: print "bad"
    else: print "good"
