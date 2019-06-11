x = input()
y = input()

if y <= x:
    print "Enter the speed limit: Enter the recorded speed of the car: Congratulations, you are within the speed limit!"
elif y > x and y - x in range(1, 21):
    print 'Enter the speed limit: Enter the recorded speed of the car: You are speeding and your fine is $100.'
elif y > x and y - x in range(21, 31):
    print 'Enter the speed limit: Enter the recorded speed of the car: You are speeding and your fine is $270.'
elif y > x and y - x >= 31:
    print 'Enter the speed limit: Enter the recorded speed of the car: You are speeding and your fine is $500.'


