# --- IMPORTS ---
from sys import stdin

input = stdin.readline

# --- START OF TEMPLATE ----
def p2d(matrix):
    for line in matrix:
        print line

def readStr():
    return input()

def readInt():
    return int(input())
# ---- END OF TEMPLATE ---

arr = []

def cutOut(cx, cy):
    # @top left
    for i in range(cy):
        for j in range(cx):
            arr[i][j] = 1

    # @top right
    for i in range(cy):
        for j in range(x-cx, x):
            arr[i][j] = 1

    # @bottom left
    for i in range(y-cy, y):
        for j in range(cx):
            arr[i][j] = 1

    # @bottom right
    for i in range(y-cy, y):
        for j in range(x-cx, x):
            arr[i][j] = 1

def simulate(xi, yi, steps):
    arr[xi][yi] = 1
    #               0      1     2      3     4      5    6     7   8    9    10    11
    # Sequence --> Right, Down, Right, Down, Left, Down, Left, Up, Left, Up, Right, up
    for i in range(12):
        # !!!! IMPORTANT !!!!
        if steps == 0:
            return xi, yi

        # @move right
        if i in [0, 2, 10]:
            while True:
                if yi == (x-1) or arr[xi][yi+1] == 1 or steps == 0 or arr[xi-1][yi] == 0:
                    break
                else:
                    yi += 1
                    arr[xi][yi] = 1
                    steps -= 1

        # @move down
        elif i in [1, 3, 5]:
            while True:
                if xi == (y-1) or arr[xi+1][yi] == 1 or steps == 0 or arr[xi][yi+1] == 0:
                    break
                else:
                    xi += 1
                    arr[xi][yi] = 1
                    steps -= 1

        # @move left
        elif i in [4, 6, 8]:
            while True:
                if yi == 0 or arr[xi][yi-1] == 1 or steps == 0 or arr[xi+1][yi] == 0:
                    break
                else:
                    yi -= 1
                    arr[xi][yi] = 1
                    steps -= 1

        # @move up
        elif i in [7, 9, 11]:
            while True:
                if xi == 0 or arr[xi-1][yi] == 1 or steps == 0 or arr[xi][yi-1] == 0:
                    break
                else:
                    xi -= 1
                    arr[xi][yi] = 1
                    steps -= 1


if __name__ == '__main__':
    x = readInt() # total width
    y = readInt() # total height
    arr = [[0 for i in range(x)] for j in range(y)]
    cx = readInt() # cut out width
    cy = readInt() # cut out height
    cutOut(cx, cy)
    steps = readInt()
    print simulate(0, 3, steps)
