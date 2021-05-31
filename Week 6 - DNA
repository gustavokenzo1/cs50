# Check if user typed everything needed correctly
# Open database and sequences to read into memory
# Check largest STR quantity
# Check if it matches some person

from sys import argv, exit
from csv import reader, DictReader

# Check how many args the user wrote, if it's different from 3, teach how to use and exit
if len(argv) != 3:
    print("Usage: python dna.py database.csv sequences.txt")
    exit()

# Open database to read
with open(argv[1], "r") as csvfile:
    
    # Make a list out of it
    csvreader = list(reader(csvfile))
    
    # Remove first collum
    csvreader[0].remove("name")
    
    # "i" gives each separate segment of DNA (a given set of nucleotides) like ATCG
    i = csvreader[0]

# Open sequences to read and... well... read it into memory
with open(argv[2], "r") as txtfile:
    txtreader = txtfile.read()

# Create an array
Max = []

# Loop through each set of DNA, i.e.: for the short list, loop through all 3 of them
for j in range(len(i)):
    
    # Put 0 in the array so we can compare it later
    Max.append(0)
    
    # Another loop to iterate through each nucleotide of the sequence given
    for k in range(len(txtreader)):
        count = 0
        
        # If some nucleotide + the lenght of some set of DNA (STR) is equal to that STR, keep going
        if txtreader[k:(k + len(i[j]))] == i[j]:
            l = 0
            # l is an int to store the lenght of the STR so we can see how many we have together
            while txtreader[(k + l):(k + l + len(i[j]))] == i[j]:
                # Update the count of how many are together
                count += 1
                
                # Go to the next STR
                l += len(i[j])
            
            # Then, if that count surpasses whatever we had earlier (0 for the first loop), update it
            # No need for temp variable because python <3
            if count > Max[j]:
                Max[j] = count

# Turn Max into a list of strings rather than ints
Max = list(map(str, Max))

# Create a new list with the same stuff from the database so we can compare
new = list(csvreader)

for i in new:
    # Skipping the first collum (names), if number of STRs from Max match with database, print name
    if i[1:] == Max:
        print(f"{i[0]}")
        break
    
    # If it doesn't match, then it doesn't match, what can I do?
    elif i == new[-1]:
        print("No match")
