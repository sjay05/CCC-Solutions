"""
author: sjay05
"""

# Code doesn't work when range is from -1,000,000,000 to +1,000,000,000
# Code also doesn't work at all (in progress)
import random
import copy

line1 = raw_input().split()
line2 = raw_input().split()
line3 = raw_input().split()
sample_input = [
    [x for x in line1],
    [y for y in line2],
    [z for z in line3]
]

if line1 == ['X', 'X', 'X']:
    if line2 == ['X', 'X', 'X']:
        if line3 == ['X', 'X', 'X']:
            print "1 2 3"
            print '1 2 3'
            print '1 2 3'

for a in range(3):
    for b in range(3):
        if sample_input[a][b] != 'X':
            sample_input[a][b] = int(sample_input[a][b])

def vertical_neighbors(a, b, array):
    if a == 0:
        neighbor1 = array[a + 1][b]
        neighbor2 = array[a + 2][b]
    elif a == 1:
        neighbor1 = array[a - 1][b]
        neighbor2 = array[a + 1][b]
    elif a == 2:
        neighbor1 = array[a - 2][b]
        neighbor2 = array[a - 1][b]

    if neighbor1 != 'X' and neighbor2 != 'X':
        return True
    else:
        return False

def horizontal_neighbors(a, b, array):
    if b == 0:
        neighbor1 = array[a][b + 1]
        neighbor2 = array[a][b + 2]
    elif b == 1:
        neighbor1 = array[a][b - 1]
        neighbor2 = array[a][b + 1]
    elif b == 2:
        neighbor1 = array[a][b - 2]
        neighbor2 = array[a][b - 1]

    if neighbor1 != 'X' and neighbor2 != 'X':
        return True
    else:
        return False


def fill(array, recursion):
    for i in range(3):
        for j in range(3):
            if array[i][j] == 'X':
                if horizontal_neighbors(i, j, array):
                    if  j == 1:
                        d = (array[i][j + 1] - array[i][j - 1])
                        if d % 2 == 0:
                            if -1000000001 < array[i][j - 1] + d / 2 < 100000001:
                                array[i][j] = array[i][j - 1] + d / 2
                            else:
                                return False
                        elif recursion and d % 2 != 0:
                            return False
                    if j == 0:
                        d = array[i][j + 2] - array[i][j + 1]
                        if -1000000001 < array[i][j] - d / 2 < 100000001:
                            array[i][j] = array[i][j] - d
                        else:
                            return False
                    if j == 2:
                        d = array[i][j - 1] - array[i][j - 2]
                        if -1000000001 < array[i][j - 1] + d < 100000001:
                            array[i][j] = array[i][j - 1] + d
                        else:
                            return False
                if vertical_neighbors(i, j, array):
                    if i == 0:
                        d = array[i + 2][j] - array[i + 1][j]
                        if -1000000001 < int(array[i + 1] - d) < 100000001:
                            array[i][j] = array[i + 1] - d
                        else:
                            return False
                    if i == 1:
                        d = (array[i + 1][j] - array[i - 1][j])
                        if d % 2 == 0:
                            if -1000000001 < array[i - 1][j] + d / 2 < 100000001:
                                array[i][j] = array[i - 1][j] + d / 2
                            else:
                                return False
                        elif recursion and d % 2 != 0:
                            return False
                    if i == 2:
                        d = array[i - 1][j] - array[i - 2][j]
                        if -1000000001 < array[i - 1][j] + d < 100000001:
                            array[i][j] = array[i - 1][j] + d
                        else:
                            return False

    return array

original = copy.deepcopy(fill(sample_input, False))

def possible_location(array):
    for i in range(3):
        for j in range(3):
            if array[i][j] == 'X':
                if i == 0 or i == 1:
                    if array[i+1][j] != 'X':
                        return i,j
                    elif i == 1:
                        if array[i-1][j] != 'X':
                            return i,j
                if i == 2:
                    if array[i-1][j] != 'X':
                        return i,j
                if j == 0 or j == 1:
                    if array[i][j+1] != 'X':
                        return i,j
                    if j == 1:
                        if array[i][j-1] != 'X':
                            return i,j
                if j == 2:
                    if array[i][j-1] != 'X':
                        return i,j
    return False

new_input = copy.deepcopy(original)

def generate_arithmetic(array):
    while True:
        if not possible_location(array):
            return array
        else:
            i,j = possible_location(array)
            array[i][j] = random.randint(-100, 100)
            if not fill(array, True):
                array = original
            else:
                array = fill(array, True)

if line1 == ['X', 'X', 'X'] and line2 == ['X', 'X', 'X'] and line3 == ['X', 'X', 'X']:
    pass
else:
    final =  generate_arithmetic(new_input)
    for i in range(3):
        arr = final[i]
        print "%s" % arr[0], arr[1], arr[2]
