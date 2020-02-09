from sys import stdin
input = stdin.readline

def good(n):
    a = str(n)
    b = a[::-1]
    for ci in range(len(a)):
        if a[ci] in ["0", "1", "8"] and a[ci] != b[ci]:
            return False
        elif a[ci] == "9" and b[ci] != "6":
            return False
        elif a[ci] == "6" and b[ci] != "9":
            return False
        elif a[ci] not in ["1", "0", "8", "6", "9"]:
            return False

    return True

def main():
    m = int(input())
    n = int(input())
    tc = 0
    for i in range(m, n+1):
        if good(i):
            tc += 1

    print tc

main()
