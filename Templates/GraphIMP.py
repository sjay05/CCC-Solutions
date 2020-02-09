from Queue import Queue
from Queue import PriorityQueue

class Graph:
    def __init__(self, MAXN):
        self.MAXN = MAXN
        self.adj = {i: [] for i in range(MAXN)}

    def add_Edge(self, a, b):
        self.adj[a].append(b)

    def getAdj(self, a):
        return self.adj[a]

    def SCC(self, src, dest):
        # You need ADJ list with 1 weight
        previous = {}
        dist = {i: 0 for i in range(10)}
        q = Queue()
        q.put(src)
        while not q.empty():
            v = q.get()
            for u in self.adj[v]:
                if not dist[u]:
                    dist[u] = dist[v] + 1
                    previous[u] = v
                q.put(u)

        x = dest
        path = [dest]
        while True:
            if x == src or x not in previous.keys():
                break
            else:
                path.append(previous[x])
                x = previous[x]

        path.reverse()
        return path

    def SSSP(self, src, dest):
        # You need ADJ list with (to, weight)
        dist = {i: float('INF') for i in range(self.MAXN)}
        dist[src] = 0
        pq = PriorityQueue()
        pq.put((0, src))
        while not pq.empty():
            v = pq.get()[1]
            for u in self.adj[v]:
                n, weight = u[0], u[1]
                if dist[v] + weight < dist[n]:
                    dist[n] = dist[v] + weight
                    pq.put((dist[n], n))

        return dist[dest]

    def connected(self, a, b):
        visited = []

        def dfs(n):
            if n not in visited:
                visited.append(n)
                for n in self.adj[n]:
                    dfs(n)

        dfs(a)
        if b not in visited:
            return False
        else:
            return True


g = Graph(10)
g.add_Edge(1, 2)
g.add_Edge(1, 4)
g.add_Edge(4, 5)
g.add_Edge(5, 6)
g.add_Edge(4, 6)

print g.SCC(1, 6)
