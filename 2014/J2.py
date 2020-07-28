"""
author: sjay05
"""
i = 0
num = input()
votes = raw_input()
a = 0
b = 0

def transfer_string_to_list(votes):
    i = 0
    list = []
    while i < len(votes):
        list.append(votes[i])
        i += 1
    return list

for i in range(0, num):
    if votes[i] == 'A':
        a += 1
    else:
        b += 1

if a > b:
    print "A"
elif b > a:
    print 'B'
else:
    print 'Tie'
