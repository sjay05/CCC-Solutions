from sys import stdin

input = stdin.readline

N = int(input())
comps = []


if __name__ == '__main__':
    name = ""
    R, S, D = 0, 0, 0
    for i in range(N):
        name, R, S, D = input().split()
        R = int(R)
        S = int(S)
        D = int(D)
        FORM = (2*R) + (3*S) + D
        comps.append([name, FORM])

    comps.sort(key = lambda x: x[1])
    l = len(comps)

    a = []
    # find all MAX
    for v in comps:
        if v[1] == comps[len(comps)-1][1]:
            a.append(v)

    b = []
    # find all second MAX
    for v in comps:
        if v[1] == comps[len(comps)-2]:
            b.append(v)

    maxName, maxVal = "", 0

    for v in comps:
        if v[1] > maxVal:
            maxName = v[0]
            maxVal = v[1]
        elif v[1] == maxVal:
            if v[0] < maxName:
                maxName = v[0]
                maxVal = v[1]
    print maxName

    nName, nVal = "", 0
    # fine nextMax
    for v in comps:
        if nVal < v[1] < maxVal:
            nVal = v[1]
            nName = v[0]
        elif v[1] == nVal:
            if v[0] < nName:
                nName = v[0]
                nVal = v[1]
    print nName


