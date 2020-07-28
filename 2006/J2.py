"""
author: sjay05
"""
m = input()
n = input()
count = 0

for i in range(1, m+1):
    if 10 - i in range(1, n+1):
        count += 1

print "There is %s ways to get the sum 10." %count
