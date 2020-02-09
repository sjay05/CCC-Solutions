from sys import stdin
input = stdin.readline

x = int(input())
m = int(input())

def main():
    for n in range(1, m):
        if (x*n) % m == 1:
            return n
    return "No such integer exists."

print main()
