from Queue import Queue

class Graph:
    def __init__(self, MAXN):
        self.MAXN = MAXN
        self.adj = {i: [] for i in range(1, MAXN+1)}

    def addEdge(self, a, b):
        self.adj[a].append(b)

    def scc(self, src, dest):
        q = Queue()
        dist = {i: 0 for i in range(1, self.MAXN+1)}
        q.put(src)
        while not q.empty():
            u = q.get()
            for v in self.adj[u]:
                if not dist[v]:
                    dist[v] = dist[u] + 1
                    q.put(v)

        return dist[dest]

