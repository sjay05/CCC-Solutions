"""
author: sjay05
"""
s = raw_input()
lengths = []

for i in range(len(s)):
    for j in range(i, len(s)):
        s2 = [i:j+1]
        if s2 == s2[::-1]:
            lengths.append(len(s2))

print sorted(lengths)[len(lengths)-1]
