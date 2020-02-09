import sys

N = input()
arr = raw_input().split()
arr = [int(i) for i in arr]

# DP globals
dp = [0] * 4002
ma = [0] * 2001 

for i in arr:
    ma[i] += 1 

def nailed_it_2():
    for x in range(1, 2001):
        for y in range(x, 2001):
            if x == y:
                dp[x+y] += ma[x]/2
            else:
                dp[x+y] += min(ma[x], ma[y])
    
    mh = 0
    for i in dp:
        if i > mh: mh = i
    
    ff = 0
    for i in dp:
        if i == mh: ff += 1
          
    print mh, ff
    
nailed_it_2()
