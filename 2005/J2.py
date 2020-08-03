"""
author: sjay05
"""
from sys import stdin

input = stdin.readline

A = int(input())
B = int(input())

def getDivisors(n):
    c = 0
    for i in range(1, n+1):
        if n % i == 0:
            c += 1
    return c

if __name__ == '__main__':
    mc = 0
    for n in range(A, B+1):
        if getDivisors(n) == 4:
            mc += 1

    print "The number of RSA numbers between %s and %s is %s" % (A, B, mc)
