#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, string argv[])
{
    //Checking for 2 arguments in the command line
    if (argc == 2 && argv[2] >= 0)
    {
        //Convert string to an integer
        int k = atoi(argv[1]);

        // Prompt user for input
        string plaintext = get_string("plaintext: ");

        //Encrypting
        printf("ciphertext: ");

        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            //Checking if a character is an alphabetical letter
            if (isalpha(plaintext[i]))
            {
                //Checking the case of the letter
                if (islower(plaintext[i]))
                {
                    printf("%c", (97 + ((plaintext[i] - 97 + k) % 26)));
                }
                if (isupper(plaintext[i]))
                {
                    printf("%c", (65 + ((plaintext[i] - 65 + k) % 26)));
                }
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
}