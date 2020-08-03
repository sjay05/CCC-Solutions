"""
author: sjay05
"""
T = raw_input()
S = raw_input()

state = False
s = list(S)

if S in T:
    print "yes"

else:
    for i in range(len(S)):
        x = s[0]
        s = s[1:]
        s.insert(len(s), x)
        a = ""
        for i in s: a += i
        if a in T:
            print "yes"
            state = True
            break

    if not state:
        print "no"
