"""
author: sjay05
"""
# 2009 J5 - Graph Theory Using Python 2.7
"""
Algorithm: BFS and ADJ LIST Graph Representation

Operations [i, d, n, f] can be obtained from ADJ LIST.

For operation [s], run BFS by maintaining the distance from src vertex. Mantain visited and distance.

For operation [f], run 2 nested loops to find friends of "friends". Maintain these nodes in a set, because nodes might reoccur.
"""

import Queue
qu = Queue.Queue()
visited = [False] * 50
distance = [0] * 50

# Initialization of ADJ LIST
graph = {1: [6], 2: [6], 3: [4, 5, 6, 15], 4: [3, 5, 6], 5: [3, 4, 6], 6: [1, 2, 3, 4, 5, 7], 7: [6, 8],
         8: [7, 9], 9: [8, 10, 12], 10: [9, 11], 11: [10, 12], 12: [9, 11, 13], 13: [12, 14, 15], 14: [13],
         15: [3, 13], 16: [17, 18], 17: [16, 18], 18: [16, 17], }

# BFS on Graph with SRC Node (x) from INPUT FORMAT: s, x, y


def bfs(node):
    visited[node] = 1
    qu.put(node)
    while (not qu.empty()):
        s = qu.get()
        for n in graph[s]:
            if visited[n]:
                continue
            # Mark node to TRUE
            visited[n] = True
            # Put node in QUEUE
            qu.put(n)
            # Update distance
            distance[n] = distance[s]+1


# MAINTAIN OUTPUT IN LIST
OUTPUT = []

while True:
    q = raw_input()
    if q == 'q':
        break
    else:
        command = q
        if q == "i":  # Add new friendship from x to y
            x = input()
            y = input()
            if x not in graph.keys():
                graph[x] = [y]
            else:
                graph[x].append(y)
            if y not in graph.keys():
                graph[y] = [x]
            else:
                graph[y].append(x)
        if q == "d":  # Remove/Delete friendship from x to y
            x = input()
            y = input()
            graph[x].remove(y)
            graph[y].remove(x)
        if q == "n":  # How many friends does x have
            x = input()
            OUTPUT.append(len(graph[x]))
        if q == "f":  # How many friends of friends does x have
            x = input()
            count = []
            for i in graph[x]:
                for j in graph[i]:
                    if j != x and j not in graph[x]:
                        count.append(j)
            count = set(count)
            OUTPUT.append(len(count))
        if q == "s":  # shortest path from x to y
            x = input()
            y = input()
            bfs(x)
            if distance[y] == 0:
                OUTPUT.append("Not connected")
            else:
                OUTPUT.append(distance[y])
            qu = Queue.Queue()
            visited = [False] * 50
            distance = [0] * 50

for i in OUTPUT:
    print i
