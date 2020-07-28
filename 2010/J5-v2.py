"""
author: sjay05
"""
import Queue
q = Queue.Queue()

visited = []
distance = {}

x,y = map(int, raw_input().split())
src = (x,y)
x,y = map(int, raw_input().split())
dest = (x,y)

for i in range(1, 9):
    for j in range(1, 9):
        pair = (i,j)
        distance[pair] = 0

def check(tup):
    x = tup[0]
    y = tup[1]
    if x >= 1 and x <= 8:
        if y >= 1 and y <= 8:
            return True

    return False

def get_neighbors(node):
    final = []
    x = node[0]
    y = node[1]
    a = (x+1, y+2)
    b = (x+2, y+1)
    c = (x+2, y-1)
    d = (x+1, y-2)
    e = (x-1, y-2)
    f = (x-2, y-1)
    g = (x-2, y+1)
    h = (x-1, y+2)
    templ = [a,b,c,d,e,f,g,h]
    for i in templ:
        if check(i):
            final.append(i)

    return final


def bfs(node):
    visited.append(node)
    q.put(node)
    while not q.empty():
        s = q.get()
        for i in get_neighbors(s):
            if i in visited:
                continue
            visited.append(i)
            q.put(i)
            distance[i] = distance[s]+1

bfs(src)
print distance[dest]
