"""
author: sjay05
"""
number_of_wins = 0
count = 1
while count <= 6:
  x = raw_input()
  if x != "W" and x != "L":
      print "Not able to read"
  if x == "W":
      number_of_wins = number_of_wins + 1
  count += 1

if number_of_wins == 5 or number_of_wins == 6:
  print "1"
elif number_of_wins == 3 or number_of_wins == 4:
  print "2"
elif number_of_wins == 1 or number_of_wins == 2:
  print "3"
else:
  print "-1"
