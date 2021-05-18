#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// I put it here to make it a global variable, but not sure if this was needed
// Count the size of the dictionary
int counter = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
// 26^4 = first four letters because it sounds good
const unsigned int N = 456976; 

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Had to convert everything to lowercase because check50 wasn't liking it
    int j = strlen(word);
    // Store every word in this temporary array (+1 for \0)
    char lower[LENGTH + 1];
    
    // Iterate through each letter and lower it's case
    for (int i = 0; i < j; i++)
    {
        lower[i] = tolower(word[i]);
    }
    
    // Assign a hash to the lowercase words
    int hashnum = hash(lower);
    
    // Pointer to point to the position of the lowercase words in table
    node *tmp = table[hashnum];
    
    // If it doesn't point to anything, return false
    if (tmp == NULL)
    {
        return false;
    }
    
    // While it points to something, return true if word is the same. If it isn't go to the next word
    while (tmp != NULL)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }

        tmp = tmp->next;

    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    // Got this, and adapted, from:
    // https://stackoverflow.com/questions/7666509/hash-function-for-string
    unsigned long hash = 5381;
    int c = *word;

    while (c == (*word++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary to read (remember to close it later)
    FILE *dict = fopen(dictionary, "r");
    
    // If it doesn't work, then it must not exist, i think, idk, probably
    if (dict == NULL)
    {
        printf("File does not exist.\n");
        return false;
    }
    
    // Create an array to store words from dictionary
    char word[LENGTH + 1];
    
    // fscanf strings from dict into word unitl it reaches End of File
    while (fscanf(dict, "%s", word) != EOF)
    {
        // Allocate memory for each node
        // Just like how David lifted each wooden box in the lecture
        node *n = malloc(sizeof(node));
        
        // If pointer is pointing to NULL, close and return false
        if (n == NULL)
        {
            unload();
            return false;
        }
        
        // Copy from word into pointer n
        strcpy(n->word, word);
        
        // Assign an index for that word
        unsigned int index = hash(word);
        
        // Help orphans!!! Adopt!
        n->next = table[index];
        table[index] = n;
        
        // Increase counter
        counter++;
    }
    // Close dictionary
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter; // Hardest one yet
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // Iterate through each node
    for (int i = 0; i < N; i++)
    {
        // Pointer to point at table's i'th word
        node *n = table[i];
        
        // While it points to something, temporary variable to help not to leak any memory
        while (n != NULL)
        {
            node *tempo = n;
            n = n->next;
            free(tempo);
        }
        
        // If it doesn't point to anything and is at the end of the list, return true
        if (n == NULL && i == (N - 1))
        {
            return true;
        }
    }
    return false;
}
