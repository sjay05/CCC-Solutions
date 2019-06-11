main = input()
c = 0
list = []
inp = ""
while c < main:
    inp = raw_input()
    list.append(inp)
    c += 1

for i in range(len(list)):
    word = list[i]
    main_count = 01
    main_array = []
    for x in range(len(word)):
        if x == len(word)-1 and word[x] == word[x-1]:
            main_count += 1
            main_array.append(main_count)
            main_array.append(str(word[x]))
            break
        if x == len(word)-1 and word[x] != word[x-1]:
            main_count = 1
            main_array.append(main_count)
            main_array.append(str(word[x]))
            break
        elif word[x] == word[x+1]:
            main_count += 1
        elif word[x] != word[x+1]:
            main_array.append(main_count+1)
            main_array.append(str(word[x]))
            main_count = 0

    main_str = ""
    for o in range(len(main_array)):
        main_str += str(main_array[o])
        main_str += (" ")

    print main_str