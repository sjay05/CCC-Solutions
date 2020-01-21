from sys import stdin
input = stdin.readline

a1, b1 = input().split()
a2, b2 = input().split()
a3, b3 = input().split()

steps, initial, final = input().split()
steps = int(steps)

memoize = set()

def rec(it, seq, moves):
    if it == steps and seq == final:
        return moves
    
    if it == steps:
        return False
    
    setup = (it, seq)
    if setup in memoize:
        return False
    memoize.add(setup)
    
    for rule, (a, b) in enumerate([(a1, b1), (a2, b2), (a3, b3)], 1):
        pos = -1
        while True:
            pos = seq.find(a, pos+1)
            
            if pos == -1:
                break
            
            ns = seq[:pos] + b + seq[pos + len(a):] 
            output = rec(it+1, ns, moves+[[rule, pos+1, ns]])
            if output:
                return output
    
    return False

value = rec(0, initial, [])

if not value:
    print "IMPOSSIBLE"
else:
    for a, b, c in value:
        print a, b, c
            
        