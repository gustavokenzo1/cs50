from cs50 import get_float

# Prompt user for change owed
cash = get_float("Change owed: ")

# Keep propting till user types a non-negative number
while cash < 0:
    cash = get_float("Change owed: ")

# Change to integers cause it's prettier   
change = cash * 100

# Start variable coins
coins = 0

# Keep calling these functions until change owed becomes less than coin value and updating coin variable
while change >= 25:
    change -= 25
    coins += 1

while change >= 10:
    change -= 10
    coins += 1
    
while change >= 5:
    change -= 5
    coins += 1
    
while change >= 1:
    change -= 1
    coins += 1
    
# When it finally reaches 0 change owed, print amount of coins
if change == 0:
    print(f"{coins}")
