from sys import stdin

input = stdin.readline

length, width = map(int, input().split())

grid = [input() for i in range(length)]
dead = set()
for i in range(length):
    # print grid[i].rstrip("\n")
    for j in range(width):
        if grid[i][j] == "S":
            queue = [[i, j, 0]]
        if grid[i][j] != "C":
            continue
        dead.add((i, j))
        for a, b in [0, 1], [0, -1], [-1, 0], [1, 0]:
            I = i
            J = j
            while grid[I + a][J + b] != "W":
                I += a
                J += b
                if grid[I][J] in "S.":
                    dead.add((I, J))

vis = {}
loop = set()
for x, y, moves in queue:
    while grid[x][y] in "UDLR":
        if grid[x][y] == "U":
            if grid[x - 1][y] == "W":
                break
            x -= 1
        elif grid[x][y] == "D":
            if grid[x + 1][y] == "W":
                break
            x += 1
        elif grid[x][y] == "L":
            if grid[x][y - 1] == "W":
                break
            y -= 1
        elif grid[x][y] == "R":
            if grid[x][y + 1] == "W":
                break
            y += 1
        if (x, y) in loop:
            break
        loop.add((x, y))
    if (x, y) not in dead and (x, y) not in vis and grid[x][y] in "S.":
        vis[x, y] = moves
        for a, b in [0, 1], [0, -1], [-1, 0], [1, 0]:
            a += x
            b += y
            queue.append([a, b, moves + 1])

for i in range(length):
    for j in range(width):
        if grid[i][j] == ".":
            print(vis.get((i, j), -1))
