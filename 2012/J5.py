from sys import stdin

input = stdin.readline

def helper():
    if Q == 1:
        print sum(max(i,j) for i, j in zip(D, P))
    else:
        P.reverse()
        print sum(max(i,j) for i, j in zip(D, P))

if __name__ == '__main__':
    Q = int(input())
    N = int(input())
    D = sorted(map(int, input().split()))
    P = sorted(map(int, input().split()))
    helper()
