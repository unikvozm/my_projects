import sys
from cs50 import get_string

# Checking for 2 arguments in the command line
if len(sys.argv) == 2:

    # Convert string to an integer
    k = int(sys.argv[1])
    if k < 0:
        print("k should be non-negative")
        exit(1)

    # Prompt user for input
    plaintext = get_string("plaintext: ")

    # Encrypting
    print("ciphertext: ", end="")

    for c in plaintext:
        if c.isalpha():
            if c.islower():
                c = chr(ord('a') + (ord(c) - ord('a') + k) % 26)
                print(c, end="")
            if c.isupper():
                c = chr(ord('A') + (ord(c) - ord('A') + k) % 26)
                print(c, end="")
        else:
            print(c, end="")
    print()
else:
    print("Usage: python caesar.py k")
    exit(1)
