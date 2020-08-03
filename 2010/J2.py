"""
author: sjay05
"""
a = input()
b = input()
c = input()
d = input()
s = input()

sum_for_nikky = 0
sum_for_byron = 0

while True: #for nikky
    focus1 = a
    if sum_for_nikky + focus1 <= s:
        sum_for_nikky += focus1
    else:
        break
    focus1 = b

while True: #for Byron
    focus2 = c
    if sum_for_byron + focus2 <= s:
        sum_for_byron += focus2
    else:
        break
    focus2 = d

if sum_for_byron > sum_for_nikky:
    print "Byron"
elif sum_for_nikky > sum_for_byron:
    print "Nikky"
elif sum_for_nikky == sum_for_byron:
    print "Tied"
