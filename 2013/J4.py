total_number_of_minutes = input()
c = input()
list = []
for i in range(c):
    list.append(input())

#list = [5, 4, 3, 2, 1]

new_list = sorted(list)

count = 0
sum = 0
for x in new_list:
    if sum + x <= total_number_of_minutes:
        sum += x
        count += 1

print(count)