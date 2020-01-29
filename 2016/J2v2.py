from sys import stdin

input = stdin.readline

matrix = []

def main():
    for i in range(4):
        line = input().split()
        line = [int(i) for i in line]
        matrix.append(line)

def sumOf(arr):
    sum = 0
    for i in arr:
        sum += i
    return sum

def check():
    # Check rows
    sum = sumOf(matrix[0])
    for line in matrix:
        if sumOf(line) != sum:
            return "not magic"
    # check columns
    col1 = []
    for i in range(4):
        col1.append(matrix[i][0])
    sum = sumOf(col1)
    for i in range(4):
        column = []
        for j in range(4):
            column.append(matrix[j][i])
        if sumOf(column) != sum:
            return "not magic"

    return "magic"

main()
print check()