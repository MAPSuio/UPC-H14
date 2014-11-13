from sys import stdin

# read the first line of input and convert it to a number
n = int(stdin.next())

# loop through all the remaining lines in the input
for line in stdin:
    # convert all the number strings to integers
    numbers = map(int, line.split())

    # find the sum and print the result
    print sum(numbers)
