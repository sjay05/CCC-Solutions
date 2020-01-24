from sys import stdin

input = stdin.readline


# ---- Templates: -----
def gen(val, length):
    return [val] * length


def p2d(matrix):
    for line in matrix:
        print line


# ---- END OF Templates ----


if __name__ == '__main__':
    N = int(input())
    for i in range(N):
        string = input()
        output = ""
        count = 0
        for index in range(len(string)):
            if index == 0:
                count += 1
            else:
                if string[index] != string[index - 1]:
                    output += (str(count) + " " + string[index - 1] + " ")
                    count = 1
                else:
                    count += 1
        print output
