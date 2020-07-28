"""
author: sjay05
"""
from sys import stdin
input = stdin.readline

ins = []
speeds = []

def simulate():
    cur, prev = 0, 0
    for x in ins:
        t, d = x[0], x[1]
        if t == 0:
            cur = d
        else:
            sp = float(abs(d-cur))/float((t-prev))
            prev, cur = t, d
            speeds.append(sp)


if __name__ == '__main__':
    N = int(input())
    for i in range(N):
        t, d = map(int, input().split())
        ins.append((t, d))

    ins.sort()
    simulate()
    print "%.6f" % max(speeds)
