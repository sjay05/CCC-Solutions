"""
author: sjay05
"""
from sys import stdin

input = stdin.readline

q = int(input())
jars = []

if __name__ == '__main__':
    for i in range(3):
        jars.append(int(input()))

    jarN = 1
    plaC = 0
    while True:
        if q <= 0:
            print "Martha plays %s times before going broke." % plaC
            break

        if jarN == 1:
            if jars[jarN-1] == 34:
                jars[jarN-1] = 0
                q -= 1
                q += 30
            else:
                jars[jarN - 1] += 1
                q -= 1
            jarN = 2
            plaC += 1
        elif jarN == 2:
            if jars[jarN-1] == 99:
                jars[jarN - 1] = 0
                q -= 1
                q += 60
            else:
                jars[jarN - 1] += 1
                q -= 1
            jarN = 3
            plaC += 1
        elif jarN == 3:
            if jars[jarN-1] == 9:
                jars[jarN - 1] = 0
                q -= 1
                q += 9
            else:
                jars[jarN - 1] += 1
                q -= 1
            jarN = 1
            plaC += 1
