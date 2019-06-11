word1 = raw_input("First Phrase: ")
word2 = raw_input("Second Phrase: ")

if len(word1) != len(word2):
    print "It is not a anagram."
else:
    w1l = sorted([c for c in word1])
    w2l = sorted([c for c in word2])
    if w1l == w2l:
        print "It is a anagram."
    else:
        print "It is not a anagram."

