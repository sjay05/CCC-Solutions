import Queue
qu = Queue.Queue()
visited = [False] * 50
distance = [0] * 50

graph = { 1: [6], 2: [6], 3: [4, 5, 6, 15], 4: [3, 5, 6], 5: [3, 4, 6], 6: [1, 2, 3, 4, 5, 7], 7: [6, 8], 
         8: [7, 9], 9: [8, 10, 12], 10: [9, 11], 11: [10, 12], 12: [9, 11, 13], 13: [12, 14, 15], 14: [13], 
         15:[3,13], 16:[17,18], 17:[16,18], 18:[16,17], }

def bfs(node):
    visited[node] = 1
    qu.put(node)
    while (not qu.empty()):
        s = qu.get()
        for n in graph[s]:
            if visited[n]:
                continue
            visited[n] = True
            qu.put(n)
            distance[n] = distance[s]+1
    
# dfs(1)
# for i in range(18):
#     print str(i) +" " +str(distance[i])

OUTPUT = []

while True:
    q = raw_input()
    if q == 'q':
        break
    else:
        command = q
        if q == "i":
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
        if q == "d":
            x = input()
            y = input()
            graph[x].remove(y)
            graph[y].remove(x)
        if q == "n":
            x = input()
            OUTPUT.append(len(graph[x]))
            #print len(graph[x])
        if q == "f":
            x = input()
            count = []
            for i in graph[x]:
                for j in graph[i]:
                    if j != x and j not in graph[x]:
                        count.append(j)
            count = set(count)
            OUTPUT.append(len(count))
        if q == "s":
            x = input()
            y = input()
            dfs(x)
            if distance[y] == 0:
                OUTPUT.append("Not connected")
                #print "Not connected"
            else:
                OUTPUT.append(distance[y])
                #print distance[y]
            qu = Queue.Queue()
            visited = [False] * 50
            distance = [0] * 50

for i in OUTPUT:
    print i