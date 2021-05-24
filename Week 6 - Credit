from cs50 import get_int
from math import floor 
# Had to search for this because python doesn't round like C

# Prompt user for number
card = get_int("Credit card number: ")

# Will use this later
cc = card

# Covert to string so we can get it's size
size = len(str(card))

# Invalidates immediatly wrong numbers
if size != 13 and size != 15 and size != 16:
    print("INVALID")

else:
    # While card is a positive number,
    # Get it's last digit
    # Divide by 10 while rounding it down, to go to the next digit
    # Sum the number to the total
    # Repeat for part2, but doubling the number and splitting after
    part1 = 0
    part2 = 0
    
    while card > 0:
        digit1 = card % 10
        card = floor(card / 10)
        part1 += digit1
            
        digit2 = card % 10
        digit2 *= 2
        card = floor(card / 10)
        separate1 = floor(digit2 / 10)
        separate2 = digit2 % 10
        part2 = part2 + separate1 + separate2
    
    # Get the total sum 
    total = part1 + part2
    
    # Check to see if last digit is 0
    if total % 10 != 0:
        print("INVALID")
        
    else:
        first_digits = 0
        
        # Divide the number by 10, while rounding down, until it gets to the first 2 numbers
        while cc > 55:
            cc = floor(cc / 10)
            first_digits = cc
        
        # For visa, only the first number is important
        visa = floor(first_digits / 10)
        
        # Check if card's size and first number match with either VISA, AMEX or MASTERCARD
        # If it doesn't, it's INVALID
        if size == 13 and visa == 4 or size == 16 and visa == 4:
            print("VISA")
            
        elif size == 15 and first_digits == 34 or size == 15 and first_digits == 37:
            print("AMEX")
            
        elif size == 16 and first_digits == 51 or size == 16 and first_digits == 52 or size == 16 and first_digits == 53 or size == 16 and first_digits == 54 or size == 16 and first_digits == 55:
            print("MASTERCARD")
            
        else:
            print("INVALID")
        
# 72 lines instead of 150 on Week 1
