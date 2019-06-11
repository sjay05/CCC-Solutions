n = 0
array = []
while n < 4:
    x = raw_input()
    array.append(x)
    n = n + 1

x = len(array) - 2
for i in range(1, (len(array)/2)+1):
    if x == 0 and array[x] == "R":
        print "Turn LEFT into your HOME."
    elif x == 0 and array[x] == "L":
        print "Turn RIGHT into your HOME."
    elif array[x] == "R":
        print "Turn %s onto %s street." % ("LEFT", array[x-1])
    else:

        print "Turn %s onto %s street." % ("RIGHT", array[x-1])

    x -= 2