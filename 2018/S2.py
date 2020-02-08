N = int(input())

def printing(grid, V=False, H=False):
    if not H and not V:
        for i in grid:
            for j in i:
                print(j, end=' ')
            print()
    elif H and not V:
        for i in range(N-1, -1,-1):
            for j in range(0, N):
                print(grid[j][i], end=' ')
            print()
    elif not H and  V:
        for i in range(0, N):
            for j in range(N-1,-1, -1):
                print(grid[j][i], end=' ')
            print()
    else:
        for i in range(N-1,-1, -1):
            for j in range(N-1,-1, -1):
                print(grid[i][j], end=' ')
            print()

grid = []
for i in range(N):
    a = [int(k) for k in input().split()]
    grid.append(a)

if grid[0][0]<grid[0][1] and grid[0][0]<grid[1][0]:
    printing(grid)
elif grid[0][2]<grid[0][1] and grid[0][2]<grid[1][2]:
    printing(grid, H=True)
elif grid[2][0]<grid[1][0] and grid[2][0]<grid[2][1]:
    printing(grid, V=True)
elif grid[2][2]<grid[2][1] and grid[2][2]<grid[1][2]:
    printing(grid, V=True, H=True)

