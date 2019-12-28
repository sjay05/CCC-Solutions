# Initialize the input distance between the cities
#distance = [0, 13, 10, 12, 5]
distance = raw_input().split()
distance = [int(i) for i in distance]

# Initialize some variables
i = 0

# create the final result as a list
result = []


while i < len(distance):
    row = []
    j = 0
    while j < len(distance):
        if j > i:
            # upper
            row.append(distance[j] + row[j-1])
        elif i > j:
            # lower
            row.append(result[j][i])
        else:
            # diagonal
            row.append(0)

        j += 1

    result.append(row) 
    i += 1


for row in result:
    print row 
