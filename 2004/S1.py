"""
author: sjay05
"""
N = input()
collections = []

for i in range(3*int(N)):
    inp = input()
    collections.append(inp)

i = 0
while True:
    if i >= 3*int(N):
        break
    else:
        group = [collections[i], collections[i+1], collections[i+2]]
        fix_free = False
        for a in range(3):
            word = group[a]
            for b in range(3):
                if group[b] != word:
                    x = word.find(group[b])
                    if x != -1:
                        if x == 0 or x+len(group[b])-1 == len(word)-1:
                            fix_free = True
                elif b != a and group[b] == word:
                    fix_free = True

        if fix_free:
            print("No")
        else:
            print("Yes")

        i+=3
