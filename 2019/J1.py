values = []
val_count = 0
while val_count < 6:
    inp = input()
    values.append(inp)
    val_count += 1

# Team A:
three_pointer = values[0] * 3
two_pointer = values[1] * 2
one_pointer = values[2]
A = three_pointer + two_pointer + one_pointer

# Team B:
three_pointer = values[3] * 3
two_pointer = values[4] * 2
one_pointer = values[5]
B = three_pointer + two_pointer + one_pointer

if A == B:
    print "T"
elif A > B:
    print "A"
else:
    print "B"

