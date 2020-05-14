arr = []

for n in range(10):
    line = raw_input().split(' ')
    sub_arr = [] 
    for val in line:
        try:
            sub_arr.append(int(val))
        except Exception as e:
            sub_arr.append(val)
    arr.append(sub_arr)

A_ord = 65

for _ in range(900):
    for r in range(0, 10):
        for c in range(0, 9):
            if type(arr[r][c]) == str:
                res, invalid = 0, False
                for op in arr[r][c].split('+'):
                    row, col = op[0], int(op[1])-1
                    row = ord(op[0]) - A_ord
                    if type(arr[row][col]) == str:
                        invalid = True
                        break
                    else:
                        res += arr[row][col]
                
                if not invalid:
                    arr[r][c] = int(res)

for line in arr:
    line_str = ""
    for val in line:
        if type(val) == str:
            line_str += "* "
        else:
            line_str += str(val) + " "
    print line_str
