"""
author: sjay05
"""
# CCC '03 - S3 / J5 - Floor Plan (GRAPH THEORY)

from sys import stdin
from Queue import Queue

input = stdin.readline

floor = []
rooms = []
t = int(input())
r = int(input())
c = int(input())

def make_pair(a, b):
    return a, b

def getN(x, y):
    a, b, e, d = (x+1, y), (x-1, y), (x, y+1), (x, y-1)
    f = []
    for item in [a, b, e, d]:
        if 0 <= item[0] <= (r - 1):
            if 0 <= item[1] <= (c - 1):
                if floor[item[0]][item[1]] == ".":
                    f.append(item)
    return f

def bfs(src):
    visited, count = [], 1
    q = Queue()
    q.put(src)
    while not q.empty():
        v = q.get()
        for u in getN(v[0], v[1]):
            if u not in visited:
                count += 1
                visited.append(u)
                floor[u[0]][u[1]] = "I"
                q.put(u)
    return count

if __name__ == '__main__':
    for i in range(r):
        s = input().rstrip("\n")
        s = list(s)
        floor.append(s)

    for i in range(r):
        for j in range(c):
            if floor[i][j] == ".":
                floor[i][j] = "I"
                rooms.append(bfs(make_pair(i, j)))

    rooms.sort(reverse = True)
    tc = 0
    for i in rooms:
        if t >= i:
            t -= i
            tc += 1
        elif t < i: break

    if tc == 1: print "1 room, %s square metre(s) left over" % t
    else: print "%s rooms, %s square metre(s) left over" % (tc, t)
