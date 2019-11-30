foundation_grid = [[0, -1], [0, -2], [0, -3], [1, -3], [2, -3], [3, -3],
                   [3, -4], [3, -5], [4, -5], [5, -5], [5, -4], [5, -3],
                   [6, -3], [7, -3], [7, -4], [7, -5], [7, -6], [7, -7],
                   [6, -7], [5, -7], [4, -7], [3, -7], [2, -7], [1, -7],
                   [0, -7], [-1, -7], [-1, -6], [-1, -5]]

directions = []

while True:
    sam_dir = raw_input().split()
    if "q" in sam_dir:
        break
    else:
        directions.append(sam_dir)

def calc_dir(directions):
    x = -1
    y = -5
    for i in range(len(directions)):
        val = directions[i][0]
        increment = int(directions[i][1])
        error = False
        if val == "l":
            for i in range(1, increment+1):
                if [x-i, y] in foundation_grid:
                    error = True
            coordinates = [x-increment, y]

        elif val == 'd':
            for i in range(1, increment+1):
                if [x, y-i] in foundation_grid:
                    error = True
            coordinates = [x, y-increment]
        elif val == 'r':
            for i in range(1, increment+1):
                if [x+i, y] in foundation_grid:
                    error = True
            coordinates = [x+increment, y]
        elif val == 'u':
            for i in range(1, increment+1):
                if [x, y+i] in foundation_grid:
                    error = True
            coordinates = [x, y+increment]

        x = coordinates[0]
        y = coordinates[1]

        if error:
            print str(x) + " " + str(y) + " DANGER"
            break
        else:
            print str(x) + " " + str(y) + " safe"



calc_dir(directions)



