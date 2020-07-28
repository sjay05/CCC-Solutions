"""
author: sjay05
"""
a = input()
b = input()
c = input()
d = input()

if d > c and c > b and b > a:
    print 'Fish Rising'
elif d < c and c < b and b < a:
    print 'Fish Diving'
elif d == c and c == b and b == a:
    print 'Fish At Constant Depth'
else:
    print 'No Fish'
