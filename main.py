print("welcome to Pig Latin")

pyg ="ay"

original = input("Enter a word: ")

if len(original) > 0 and original.isalpha():
    print (original)
    word = original.lower()
    first = original[0]
else:
    print ("empty")

new_word = word + first + pyg
new_word = new_word[:1]
print (new_word)
