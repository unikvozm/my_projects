import sys
from cs50 import get_string

# Checking for 2 arguments in the command-line
if len(sys.argv) != 2:
    print("Usage: python vigenere.py k")
    exit(1)

else:
    # Checking for non-alphabetical characters in the key
    for c in sys.argv[1]:
        if c.isalpha() != True:
            print("The key should be alphabetical only")
            exit(1)

    key = sys.argv[1]
    key_new = []

    # Changing the case of letters in the key
    for k in key:
        if k.islower():
            k = chr(ord(k) - (ord('a') - ord('A')))
        key_new.append(k)

    # Prompt user for input
    plaintext = get_string("plaintext: ")

    # Encrypting
    print("ciphertext: ", end="")
    ciphertext = []

    g = 0

    for i in range(len(plaintext)):
        # Checking if a character is an alphabetical letter
        if plaintext[i].isalpha():
            # Checking the case of the letter
            if plaintext[i].islower():
                ciphertext.append(chr(ord('a') + (ord(plaintext[i]) - ord('a') + ord(key_new[g % len(key_new)]) - ord('A')) % 26))
            else:
                ciphertext.append(chr(ord('A') + (ord(plaintext[i]) - ord('A') + ord(key_new[g % len(key_new)]) - ord('A')) % 26))
            g = g + 1
        else:
            ciphertext.append(plaintext[i])
    for c in range(len(ciphertext)):
        print(ciphertext[c], end="")
    print()