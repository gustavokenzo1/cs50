
from cs50 import get_string

# Prompt user for text
text = get_string("Text: ")

# words variable should have +1 because the last word is followed by a punctuation, and not by ' '
words = 1
sentences = 0
letters = 0

# Loop through each character
for i in range(len(text)):
    
    # If the char is a letter, update the variable
    if text[i].isalpha():
        letters += 1
    
    # If it's a space, then it means it's the end of a word
    elif text[i] == ' ':
        words += 1
    
    # If it's a punct, update the sentences variable
    elif text[i] == '.' or text[i] == '?' or text[i] == '!':
        sentences += 1

# l letters in w words ==> l -- w
# L letters in 100 words:  L -- 100

# Equation becomes: 100.l = w.L
# L = 100.l/w
# Same goes for sentences

# L is letters per 100 words
L = (letters * 100) / words

# S is sentences per 100 words
S = (sentences * 100) / words

# Coleman-Liau index
index = round(0.0588 * L - 0.296 * S - 15.8)

# Print grade according to the index
if index >= 16:
    print("Grade 16+")
    
elif index < 1:
    print("Before Grade 1")
    
else:
    print(f"Grade: {index}")
