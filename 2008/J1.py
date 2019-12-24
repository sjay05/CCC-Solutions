weight = input()
height = input()
BMI = weight/(height * height)

if BMI > 25.0:
    print "Overweight"
if 18.5 <= BMI <= 25.0:
    print "Normal weight"
if BMI < 18.5:
    print "Underweight"
