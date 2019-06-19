num = input()
first_line = raw_input().rsplit()
second_line = raw_input().rsplit()
bad = False

for i in range(num):
    if second_line[i] == first_line[i]:
        bad = True
        break
    second_i = first_line.index(second_line[i])

    if second_line[second_i] != first_line[i]:
        bad = True
        break

if bad:
    print 'bad'
else:
    print 'good'
