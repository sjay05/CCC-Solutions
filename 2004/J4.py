"""
author: sjay05
"""

# Keyword
a = raw_input()
# String
b = raw_input()

def letter_shift(letter1, letter2):
    diff = ord(letter1) - 65
    if ord(letter2) + diff > 90:
        new_diff = ((ord(letter2) + diff) - 90) - 1
        final = chr(new_diff+65)
        return final
    else:
        return chr(diff+ord(letter2))

def encrypt(keyword, string):
    cleaned_string = ''
    for t in range(len(string)):
        if ord(string[t]) in range(65, 91):
            cleaned_string += string[t]

    keyword_list = []
    string_list = []
    i = 0
    j = 0
    while j < len(cleaned_string):
        keyword_letter = keyword[i]
        main_letter = cleaned_string[j]
        keyword_list.append(keyword_letter)
        string_list.append(main_letter)
        if i == len(keyword)-1:
            i = 0
        else:
            i += 1
        j += 1

    final_answer = []
    for i in range(len(string_list)):
        if keyword_list[i] != 'A':
            converted = letter_shift(keyword_list[i], string_list[i])
            final_answer.append(converted)
        else:
            final_answer.append(string_list[i])

    return final_answer

output_list = encrypt(a, b)

output = ''
for x in output_list:
    output += x

print output
