"""
author: sjay05
"""
K = input()
word = raw_input()
new_word = ""

for i in range(1, len(word)+1):
    S = 3 * i + K
    l = ord(word[i-1])
    l_word = ""
    for x in range(S):
        if l == 65:
            l_word = "Z"
            l = 90
        else:
            l_word = chr(l - 1)
            l = ord(l_word)

    new_word += l_word

print new_word
