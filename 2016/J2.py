# Initializing 3 by 3 matrix
magic_inputs = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]


print "Initial numbers:", magic_inputs

# Read the list of magic numbers row wise (3 by 3)


print "Please Enter Magic numbers\n"

for row in range(0, 4):
    rinput = raw_input()
    for col, ns in enumerate(rinput.split(" ")):
        magic_inputs[row][col] = int(ns)


print "Now 3 by 3 matrix looks:", magic_inputs


# Iterate the 3 by 3 matrix and find row and column sum

row_sum = [0, 0, 0, 0]
col_sum = [0, 0, 0, 0]

for row in range(0, 4):
    for col in range(0, 4):
        row_sum[row] = row_sum[row] + magic_inputs[row][col]
        col_sum[col] = col_sum[col] + magic_inputs[row][col]

print "Row sum list:", row_sum
print "Col sum list:", col_sum

if len(set(row_sum)) == 1 and len(set(col_sum)) == 1:
    print "Magic"
else:
    print "Not Magic"











