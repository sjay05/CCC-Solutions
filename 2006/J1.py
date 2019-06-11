print "Welcome to Chip's Fast Food Emporium"
burger = input("Please enter a burger choice: ")
side = input("Please enter a side order choice: ")
drink = input("Please enter a drink choice: ")
dessert = input("Please enter a dessert choice: ")

burger_choice = {1: 461, 2: 431, 3: 420, 4: 0}
drink_choice = {1: 130, 2: 160, 3: 118, 4: 0}
side_choice = {1: 100, 2: 57, 3: 70, 4: 0}
dessert_choice = {1: 167, 2: 266, 3: 75, 4: 0}

total_sum = burger_choice[burger] + drink_choice[drink] + side_choice[side] + dessert_choice[dessert]
print "Your total Calorie amount is %s" %total_sum

