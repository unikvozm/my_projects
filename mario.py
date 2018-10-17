from cs50 import get_int

while True:
    n = get_int("Integer height: ")
    if n >= 0 and n <= 23:
        break

# Print out this many rows
for i in range(n):
    # Print out this many column
    for j in range(n - i - 1):
        print(" ", end="")
    for k in range(i + 2):
        print("#", end="")
    print()