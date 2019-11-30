metres = input()
clubs = input()
club_sizes = []
for i in range(clubs):
    size = input()
    club_sizes.append(size)

def find_num(num):
    for i in sorted(club_sizes, reverse = True):
        if num-i >= 0:
            return i

    return 0

answer = []
def golf(meters, steps):
    if meters == 0:
        answer.append(steps)
        return
    else:
        i = find_num(meters)
        if i != 0:
            golf(meters-i, steps+1)
        else:
            golf2(metres, 0, False)

methods = []
def golf2(meters, steps, final):
    if meters == 0:
        if steps not in methods:
            methods.append(steps)
            final = True
            return

    for i in sorted(club_sizes, reverse = True):
        if meters-i >= 0:
            golf2(meters-i, steps+1, False)
            if final == True:
                return


golf(metres, 0)

if answer:
    print "Roberta wins in %s strokes." % answer[0]
elif methods == []:
    print "Roberta acknowledges defeat."
else:
    print "Roberta wins in %s strokes." % methods[0]
