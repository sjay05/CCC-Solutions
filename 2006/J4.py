# Attempted Topological Sort with Graph Implementation. However UNFINISHED.

class Vertex:
    def __init__(self, name):
        self.name = name
        self.neighbors = {}
        self.visited = False

    def add_neighbor(self, to_v, weight=0):
        self.neighbors[to_v] = weight

    def get_neighbors(self):
        return self.neighbors.keys()

    def get_name(self):
        return self.name

    def __str__(self):
        return str(self.name) #+ " -> " + str([str(v_name) for v_name in self.neighbors])

    def get_neighbors_count(self):
        return len(self.neighbors)

    def set_visited(self, flag):
        self.visited = flag

    def get_visited(self):
        return self.visited


class Graph:
    def __init__(self):
        self.vert_map = {}

    def add_vertex(self, v):
        self.vert_map[v] = Vertex(v)

    def add_edge(self, from_v, to_v):
        if from_v in self.vert_map:
            self.vert_map[from_v].add_neighbor(to_v)
        else:
            v1 = Vertex(from_v)
            v1.add_neighbor(to_v)
            self.vert_map[from_v] = v1

    def get_vertex(self, from_v):
        if from_v in self.vert_map:
            return self.vert_map[from_v]
        else:
            return None

    def get_all_vertices(self):
        return self.vert_map.values()

    def dfs(self):
        tasks = []
        try:
            for aVertex in sorted(self.get_all_vertices(), reverse=True):
                if not aVertex.get_visited():
                    self.dfs_visit(aVertex, aVertex, tasks)
        except Exception as e:
            print e

        while len(tasks) > 0:
            print tasks.pop()

    def dfs_visit(self, original_start, start_vertex, tasks):
        start_vertex.set_visited(True)
        for nv in start_vertex.get_neighbors():
            if nv == original_start.get_name():
                del tasks[:]
                raise Exception("Loop Detected. Job can't be done")

            next_vertex = self.vert_map[nv]
            if not next_vertex.get_visited():
                self.dfs_visit(original_start, next_vertex, tasks)

        tasks.append(start_vertex)


g = Graph()

g.add_vertex(1)
g.add_vertex(2)
g.add_vertex(3)
g.add_vertex(4)


# first input
g.add_edge(4, 3)
g.add_edge(3, 2)
g.add_edge(2, 1)
g.add_edge(1, 3)

g.dfs()



