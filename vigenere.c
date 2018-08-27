#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Checking for 2 arguments in the command-line
    if (argc != 2)
    {
        printf("Usage: ./vigenere.c k\n");
        return 1;
    }
    else
    {
        //Checking for non-alphabetical characters in the key
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isalpha(argv[1][i]) == false)
            {
                printf("Usage: ./vigenere.c k\n");
                return 1;
            }
        }
    }
    string k = argv[1];
    // Changing the case of letters inthe key
    for (int j = 0; j < strlen(k); j++)
    {
        if (islower(k[j]))
        {
            k[j] -= ('a' - 'A');
        }
    }
    // Prompt user for input
    string plaintext = get_string("plaintext: ");

    //Encrypting
    printf("ciphertext: ");

    int g = 0;
    for (int l = 0, n = strlen(plaintext); l < n; l++)
    {
        //Checking if a character is an alphabetical letter
        if (isalpha(plaintext[l]))
        {
            //Checking the case of the letter
            if (islower(plaintext[l]))
            {
                printf("%c", (97 + ((plaintext[l] - 97 + k[g % strlen(k)] - 65) % 26)));
            }
            if (isupper(plaintext[l]))
            {
                printf("%c", (65 + ((plaintext[l] - 65 + k[l % strlen(k)] - 65) % 26)));
            }
            g++;
        }
        else
        {
            printf("%c", plaintext[l]);
        }
    }
    printf("\n");
}
