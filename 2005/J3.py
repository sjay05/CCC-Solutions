ins = []

while True:
  i = raw_input()
  if i == "SCHOOL":
    break
  else:
    ins.append(i)

ins.reverse()
i = 0
while True:
  if i == len(ins)-1:
    if ins[i] == "R":
      print "Turn LEFT into your HOME."
    else:
      print "Turn RIGHT into your HOME."
    break

  else:
    if ins[i] == "R":
      print "Turn LEFT onto %s street." % ins[i+1]
    else:
      print "Turn RIGHT onto %s street." % ins[i+1]

  i += 2
