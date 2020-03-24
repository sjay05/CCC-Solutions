from sys import stdin

input = stdin.readline

N = int(input())
pointsa = []
pointsb = []
for i in range(N):
    x = input()
    x.lstrip("\n")
    a = ""
    b = ""
    s = True
    for c in x:
        if c == ",":
            s = False
        if not s and c != "\n" and c != ",":
          b += c
        if s and c != "\n" and c != ",":
            a +=c 

    a = int(a)
    b = int(b)
    pointsa.append(a)
    pointsb.append(b)


pointsa.sort()
pointsb.sort()

print str(pointsa[0]-1) + "," + str(pointsb[0]-1)
print str(pointsa[len(pointsa)-1]+1) + "," + str(pointsb[len(pointsb)-1]+1)
