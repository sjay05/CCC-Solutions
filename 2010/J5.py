#Unfinished for Knight Hop Problem (Only Dijkstra Implementation)

import Queue as Q

ax, ay = 2, 1
bx, by = 3, 3

chess_board = [
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0]
]


class Vertex:
    def __init__(self, id):
        self.id = id
        self.cost = 10000000
        self.visited = False
        self.prev = None

    def __hash__(self):
        return hash(self.id)

    def __eq__(self, other):
        return self.id == other.id

    def __str__(self):
        return str(self.id)

    def __cmp__(self, other):
        return cmp(self.cost, other.cost)


class Edge:
    def __init__(self, src, dest, cost):
        self.src = src
        self.dest = dest
        self.cost = cost

    def __str__(self):
        return "(" + str(self.src) + "," + str(self.dest) + ")"


class Graph:
    def __init__(self):
        self.adj_list = {}

    def add_edge(self, src, dest, cost):
        e = Edge(src, dest, cost)
        l = self.adj_list.get(src, [])
        if len(l):
            l.append(e)
        else:
            self.adj_list[src] = [e]

    def find_shortest_path(self, src, dest):
        output = []
        src.cost = 0
        pq = Q.PriorityQueue()
        pq.put(src)

        while not pq.empty():
            v = pq.get()

            # If vertex is destination:
            if v == dest:
                output.append(v.id)
                # Get previous nodes (v.prev = previous node)
                while v.prev:
                    output.append(v.prev)
                    v = v.prev
                return output

            v.visited = True

            # get() function returns [] if v has no neighbors
            for e in self.adj_list.get(v, []):
                if e.dest.visited:
                    continue
                cost_so_far = e.src.cost + e.cost
                if cost_so_far < e.dest.cost:
                    e.dest.cost = cost_so_far
                    #
                    e.dest.prev = e.src
                    pq.put(e.dest)


        if not len(output):
            print "Path not found."

        return output


g = Graph()

v1 = Vertex(1)
v2 = Vertex(2)
v3 = Vertex(3)
v4 = Vertex(4)
v5 = Vertex(5)
v6 = Vertex(6)
v7 = Vertex(7)
v8 = Vertex()

g.add_edge(v1, v2, 10)
g.add_edge(v1, v3, 20)
g.add_edge(v2, v4, 5)
g.add_edge(v3, v4, 7)

path = g.find_shortest_path(v1, v4)
for i in path:
    print i
