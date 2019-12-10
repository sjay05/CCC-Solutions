# Problem Type: Graph Theory
"""
Algorithm: Use BFS
Feature #1: Run BFS to check if you can visit all nodes
Feature #2: In previous BFS, update distance to node from previous
- This problem can be solved with one run of BFS. There is no edge cost.


"""
import Queue
q = Queue.Queue()
graph = {}
visited = []
distance = {}


def create_edge(a, b):
    if a in graph.keys():
        graph[a].append(b)
    else:
        graph[a] = [b]


goneToNodes = []
shortest = []


def bfs(node):
    visited.append(node)
    q.put(node)
    while not q.empty():
        s = q.get()
        goneToNodes.append(s)
        for n in graph[s]:
            if n in visited:
                continue
            visited.append(n)
            q.put(n)
            distance[n] = distance[s]+1


N = input()
for i in range(1, N+1):
    graph[str(i)] = []
    line = raw_input().split()
    if line != ['0']:
        for j in range(1, len(line)):
            create_edge(str(i), line[j])
    else:
        # Find boundary nodes that don't connect to any other pages
        shortest.append(i)

for i in range(1, N+1):
    distance[str(i)] = 0

bfs('1')
if len(goneToNodes) >= len(graph.keys()):
    print "Y"
else:
    print "N"

l = []
# find the distance of all the boundary nodes
for i in shortest:
    l.append(distance[str(i)])

# ignore all pages that by themselves
for j in sorted(l):
    if j != 0:
        print j+1
        break