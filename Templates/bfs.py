"""
BFS Template - Python 2.7
Can be accessed with live shortcut "bfstemplate"
"""

import Queue

q = Queue.Queue()
graph = {}
visited = []
distance = {}


def bfs(node):
    visited.append(node)
    q.put(node)
    while not q.empty():
        s = q.get()
        for n in graph[s]:
            if n in visited:
                continue
            visited.append(n)
            q.put(n)
            distance[n] = distance[s] + 1
