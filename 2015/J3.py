"""
author: sjay05
"""
# Define vowels ascii list
vowels = [97, 101, 105, 111, 117]

# List comprehension to store only consonants
consonants = [c for c in range(97, 123) if c not in vowels]

"""
This function takes a consonant ascii
and returns a closest vowel character
"""
def find_closest_vowel(consonant):
    diff_list = []
    for v in vowels:
        diff_list.append(abs(v-consonant))

    min_diff = sorted(diff_list)[0]
    #return chr(consonant-min_diff)
    if consonant-min_diff in vowels:
        return chr(consonant-min_diff)
    else:
        return chr(consonant+min_diff)


"""
This function will return the next
consonant character.
"""
def find_next_consonant(consonant):
    if consonant == 122:
        return "z"
    cons_index = consonants.index(consonant)
    return chr(consonants[cons_index + 1])


# Iterate the input
input = raw_input()
output = ""

for c in input:
    if ord(c) not in vowels:
        output += c + find_closest_vowel(ord(c)) + find_next_consonant(ord(c))
    else:
        output += c


print output
