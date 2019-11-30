x = input()
y = input()

if y <= x:
    print "Congratulations, you are within the speed limit!"
elif y > x and y - x in range(1, 21):
    print 'You are speeding and your fine is $100.'
elif y > x and y - x in range(21, 31):
    print 'You are speeding and your fine is $270.'
elif y > x and y - x >= 31:
    print 'You are speeding and your fine is $500.'


