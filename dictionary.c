// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

//implementing a trie
typedef struct node
{
    bool is_word;
    struct node *children[27]; //26 letters + an apostrophe
}
node;

node *root;

//create free function
void freetrie(node *trav)
{
    //iterate over the trie
    for (int i = 0; i < 27; i++)
    {
        if (trav -> children[i] != NULL)
        {
            freetrie(trav -> children[i]);
        }
    }
    free(trav);
    return;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    //the exact place in the trie
    int i;
    //create a traverse pointer
    node *trav = root;

    //for each letter in input word
    for (int j = 0; j < strlen(word); j++)
    {
        //find the place of a letter
        if (word[j] == '\'')
        {
            i = 26;
        }
        else if (isupper(word[j]))
        {
            i = tolower(word[j]) - 'a';
        }
        else
        {
            i = word[j] - 'a';
        }

        //go to corresponding element in children
        //checking the presence of a letter in the trie
        if (trav -> children[i] == NULL)
        {
            return false;
        }
        else
        {
            trav = trav -> children[i];
        }
    }
    //if at the end of the input word, check if is_word is true
    if (trav -> is_word == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Counts words in dictionary downloaded
long dictionarywords = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    //Open the dictionary
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        return false;
    }

    //default values
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return false;
    }
    root -> is_word = false;
    for (int k = 0; k < 27; k++)
    {
        root -> children[k] = NULL;
    }
    int i; //the exact place in children

    //create a traverse pointer
    node *trav = NULL;

    //for every dictionary word, iterate through the trie
    for (int c = fgetc(inptr); c != EOF; c = fgetc(inptr))
    {

        trav = root;
        for (; c != '\n'; c = fgetc(inptr))
        {
            //find the right place for the char
            if (c >= 'a' && c <= 'z')
            {
                i = c - 'a';
            }
            else if (c == '\'')
            {
                i = 26;
            }
            else
            {
                return false;
            }

            //fill the trie
            if (trav -> children[i] != NULL)
            {
                trav = trav -> children[i]; //move to new node and continue
            }
            else
            {
                //malloc a new node, have children[i] point to it
                trav -> children[i] = malloc(sizeof(node));
                if (trav -> children[i] == NULL)
                {
                    return false;
                }
                for (int k = 0; k < 27; k++)
                {
                    trav -> children[k] = NULL;
                }
                trav = trav -> children[i];
            }
        }
        //when at the end of the word
        trav -> is_word = true;
        dictionarywords++;
    }

    //close the dictionary
    fclose(inptr);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictionarywords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < 27; i++)
    {
        if (root -> children[i] != NULL)
        {
            freetrie(root -> children[i]);
        }
    }
    return true;
}
