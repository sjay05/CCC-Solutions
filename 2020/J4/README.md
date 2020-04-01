# CCC '20 J4

We start by collecting input of ```T``` and ```S```. 

To generate the cycle shifts, we can remove the first char, and append
it to the end. 

Below is my code:
```python
# read both inputs 
T = raw_input()
S = raw_input()

state = False
s = list(S)

# if the first (cycle-shift) already exists.
if S in T:
    print "yes"

else:
    for i in range(len(S)):
        x = s[0] # first char
        s = s[1:] # all except the first char
        s.insert(len(s), x) # insert at end
        a = ""
        for i in s: a += i
        if a in T:
            print "yes"
            state = True
            break

    if not state:
        print "no"
```