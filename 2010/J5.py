# CCC 2010 J5 - Knight Hop (Graph Theory)
"""
Quick Analysis: BFS

We can simulate BFS from from a location on the chess board.
When we need to find neighbors, we can generate them 
using x and y coordinate math. However, a check will need
to be done to make sure it is a legitimate position on the
board.

"""

import Queue
q = Queue.Queue()

visited = []
distance = {}

x,y = map(int, raw_input().split())
src = (x,y) # Create a src tuple
x,y = map(int, raw_input().split())
dest = (x,y) # Create a dest tuple

# Generate all positions using nested
# loops and create distance index tuple
for i in range(1, 8+1):
    for j in range(1, 8+1):
        pair = (i,j)
        distance[pair] = 0

# Check if tuple coordinate is valid 
# in the board
def check(tup):
    x = tup[0]
    y = tup[1]
    if x >= 1 and x <= 8:
        if y >= 1 and y <= 8:
            return True
    
    return False 

# Generate neighbors given initial coordinate
# There can be a maximum of 8 moves.
def get_neighbors(node):
    final = []
    x = node[0]
    y = node[1]
    a = (x+1, y+2) 
    b = (x+2, y+1) 
    c = (x+2, y-1) 
    d = (x+1, y-2) 
    e = (x-1, y-2) 
    f = (x-2, y-1) 
    g = (x-2, y+1)
    h = (x-1, y+2)
    templ = [a,b,c,d,e,f,g,h]
    for i in templ:
        if check(i):
            final.append(i)
    
    return final 

# Run BFS from SRC position to all other
# positions in the grid and maintain the shortest
# distance.
def bfs(node):
    visited.append(node)
    q.put(node)
    while not q.empty():
        s = q.get()
        for i in get_neighbors(s):
            if i in visited:
                continue
            visited.append(i)
            q.put(i)
            distance[i] = distance[s]+1

# Run BFS and check distance on dest
bfs(src)
print distance[dest]