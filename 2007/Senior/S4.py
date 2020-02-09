"""
DP/Graph Theory - S4 (Waterpark)
"""

MAXN = 10000
adj = {} # adj[MAXN][MAXN]
dp = [0] * MAXN

def main():
    n = input()
    while True:
        x, y = map(int, raw_input().split()) 
        if x == 0 and y == 0:
            break
        adj[x].append(y)
    dp[1] = 1
    for i in range(1, n+1):
        for j in adj[i]:
            dp[j] += dp[i]

    print dp[n]

if __name__ == "__main__":
    for i in range(MAXN):
        adj[i] = []
    main()