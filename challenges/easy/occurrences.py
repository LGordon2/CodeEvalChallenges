__author__ = 'lew'

a = 'aaddbbac'
occurrences = {}
for letter in a:
    if letter in occurrences:
        occurrences[letter] += 1
    else:
        occurrences[letter] = 1

print occurrences