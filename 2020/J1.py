from sys import stdin

input = stdin.readline

S = int(input())
M = int(input())
L = int(input())
happi = (1*S) + (2*M) + (3*L)

if happi >= 10: print "happy"
else: print "sad"