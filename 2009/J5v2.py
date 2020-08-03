"""
author: sjay05
"""
import Queue

# --- START OF Templates ----
def build(val, length):
    return [val] * length


def p2d(matrix):
    for line in matrix:
        print line


def readStr():
    x = raw_input()
    return x


def readInt():
    x = int(input())
    return x


# ---- END OF Templates ----

# ---- CONSTANTS -----
graph = {1: [6], 2: [6], 3: [4, 5, 6, 15], 4: [3, 5, 6], 5: [3, 4, 6], 6: [1, 2, 3, 4, 5, 7], 7: [6, 8],
         8: [7, 9], 9: [8, 10, 12], 10: [9, 11], 11: [10, 12], 12: [9, 11, 13], 13: [12, 14, 15], 14: [13],
         15: [3, 13], 16: [17, 18], 17: [16, 18], 18: [16, 17]}


# visited = build(False, 50)
# distance = build(0, 50)

# ---- BFS TRAVERSAL ----
def bfs(q, visited, distance, node):
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

    return distance


# ---- MAKE FRIENDS ---
def makeFriends(a, b):
    if a in graph.keys():
        graph[a].append(b)
    elif a not in graph.keys():
        graph[a] = [b]
    if b in graph.keys():
        graph[b].append(a)
    elif b not in graph.keys():
        graph[b] = [a]


# --- DELETE FRIENDSHIP
def delFriend(a, b):
    graph[a].remove(b)
    graph[b].remove(a)


# --- PRINT # OF FRIENDS ---
def printFriends(a):
    print len(graph[a])


# --- FRIENDS OF FRIENDS ----
def FOF(x):
    nearest = graph[x]
    fof = set()
    for node in graph[x]:
        for adj in graph[node]:
            if adj != x and adj not in nearest:
                fof.add(adj)

    print len(fof)


# --- RUN COMMANDS ----
def runCommand(comm):
    if comm == "i":
        a = readInt()
        b = readInt()
        makeFriends(a, b)
    if comm == "d":
        a = readInt()
        b = readInt()
        delFriend(a, b)
    if comm == "n":
        a = readInt()
        printFriends(a)
    if comm == "f":
        x = readInt()
        FOF(x)
    if comm == "s":
        a = readInt()
        b = readInt()
        q = Queue.Queue()
        visited = build(False, 50)
        dist = build(0, 50)
        distance = bfs(q, visited, dist, a)
        if distance[b] == 0:
            print "Not connected"
        else:
            print distance[b]


if __name__ == '__main__':
    while True:
        command = raw_input()
        if command == "q":
            break
        else:
            runCommand(command)
