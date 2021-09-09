from cs50 import get_int

# Prompt user for height
height = get_int("Height: ")

# Keep prompting till height is not less than 1 or greater than 8
while height > 8 or height < 1:
    height = get_int("Height: ")

# Same thing but had to search how to not create a new line after printing (, end='')
# so it's not as chaotic as mario (less)
for i in range(height):
    print(' ' * (height - i - 1), end='')
    print('#' * (i + 1), end='')
    print('  ', end='')
    print('#' * (i + 1))
