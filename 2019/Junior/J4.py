# Messy Version of 2019 J4
grid = [[1, 2],[3, 4]]

def horizontal(grid, new_grid):
    for i in range(2):
        for j in range(2):
            if i == 0:
                new_grid[i][j] = grid[i+1][j]
            else:
                new_grid[i][j] = grid[i-1][j]

    return new_grid

def vertical(grid, new_grid):
    for i in range(2):
        for j in range(2):
            if j == 0:
                new_grid[i][j] = grid[i][j+1]
            else:
                new_grid[i][j] = grid[i][j-1]

    return new_grid

string = raw_input()
l = []
for i in range(len(string)):
    l.append(string[i])

for t in range(len(l)):
    if l[t] == "H":
        if t == 0:
            grid = horizontal(grid, [[0, 0],[0, 0]])
        else:
            grid = horizontal(grid, [[0, 0],[0, 0]])
    elif l[t] == "V":
        if t == 0:
            grid = vertical(grid, [[0, 0],[0, 0]])
        else:
            grid = vertical(grid, [[0, 0],[0, 0]])

for d in range(len(grid)):
    final_string = ""
    for l in range(len(grid)):
        temp = grid[d][l]
        final_string += str(temp)
        final_string += " "
    print final_string

