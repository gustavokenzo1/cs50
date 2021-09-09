from cs50 import get_int

# Prompt user for height
height = get_int("Height: ")

# Keep prompting till height(1, 8)
while height > 8 or height < 1:
    height = get_int("Height: ")

# Loop height times
for i in range(height):
    # Print space height - i - 1 times. i.e.: height 4, print 4 - 0 - 1, first line should be 3 spaces
    # Print hashtag i + 1 times. i.e.: 0 + 1 first line should have 1 #
    print(" " * (height - i - 1) + "#" * (i + 1))
