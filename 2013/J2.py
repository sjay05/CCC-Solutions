letters = ['I', 'O', 'S', 'H', 'Z', 'X', 'N']
i = 0
count = 0
input = raw_input()


while i < len(input):
    if input[i] in letters:
        count += 1
        i += 1
    elif input[i] not in letters:
        break

if count == len(input):
    print "YES"
else:
    print "NO"

