"""
author: sjay05
"""

n = raw_input()
a = raw_input()
b = raw_input()

i = 0
c = 0
while i < int(n):
    if a[i] == b[i] and a[i] == "C":
        #print "a[%s] = %s, b[%s] = %s" % (i, a[i], i, b[i])
        c = c + 1
    i += 1

print c
