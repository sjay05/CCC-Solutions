"""
author: sjay05, Arden144
"""
t = input()
s = input()
cl = []
ans = "no"
for i in range(len(s)):
    if s in t:
        ans = "yes"
        break
    s = s[-1] + s[:-1]
print(ans)
