import Queue
graph = {i:[] for i in range(10)}
dist = {i:0 for i in range(10)}

def bfs(src):
    dist[src] = 0
    q = Queue.Queue()
    q.put(src)
    while not q.empty():
        u = q.get()
        for v in graph[u]:
            if not dist[v]:
                dist[v] = dist[u] + 1
            q.put(v)

def main():
    for i in range(input()):
        f, t = map(int, raw_input().split())
        graph[f].append(t)

    bfs(1)

main()
print dist
