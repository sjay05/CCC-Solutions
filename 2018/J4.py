trees = input()
matrix = []

while True:
    test = []
    for count in range(trees):
        string = raw_input()
        test = [int(s) for s in string.split(" ")]
        matrix.append(test)

    break

def rotate(array):
    ans = []
    for main_count in range(len(array)):
        temp = []
        for zero_count in range(len(array)):
            temp.append(0)

        ans.append(temp)

    for row in range(len(array)):
        col = len(array) - 1
        origin = 0
        while col >= 0 and origin < len(array):
            ans[row][origin] = array[col][row]
            origin += 1
            col -= 1

    return ans

def check(matrix):
    outcome = False
    for g in range(len(matrix)):
        if matrix[g] != sorted(matrix[g]):
            outcome = True

    tempo = []
    for l in range(len(matrix)):
        tempo.append(matrix[l][0])

    if tempo != sorted(tempo):
        outcome = True

    if not outcome:
        return False
    elif outcome:
        return True

while True:
    if not check(matrix):
        x = matrix
        break
    else:
        matrix = rotate(matrix)
        
for i in x:
	string = ""
	for j in i:
		string += str(j) + " "
	print string

	






