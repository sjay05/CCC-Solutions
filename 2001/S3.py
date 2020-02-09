from sys import stdin
from Queue import Queue
input = stdin.readline

"""
Algorithm Outline:
- We want to check if we can get from A to B with edge (e)
removed. If no, then this is a DISCONNECTING ROAD. We can use
BFS or DFS to check if B exists in visited arr when DFS or BFS
initiated from A. 
"""

adj = {chr(i): [] for i in range(65, 90 + 1)}
edges = []

def edge(a, b):
    adj[a].append(b)
    adj[b].append(a)
    edges.append((a, b))

def bfs(n, visited, goal):
    q = Queue()
    visited.append(n)
    q.put(n)
    while not q.empty():
        s = q.get()
        for v in adj[s]:
            if v not in visited:
                visited.append(v)
                q.put(v)

    if goal in visited:
        return False
    else:
        return True

def main():
    while True:
        s = input()
        a, b = s[0], s[1]
        if a != "*" and b != "*":
            edge(a, b)
        else:
            break

    tc = 0
    for e in edges:
        a, b = e[0], e[1]
        adj[a].remove(b)
        adj[b].remove(a)
        result = bfs(a, [], b)
        if result:
            print a+b
            tc += 1
        adj[a].append(b)
        adj[b].append(a)

    print "There are %s disconnecting roads." % tc

if __name__ == '__main__':
    main()
