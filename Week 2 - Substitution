#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Check if user only typed two things
//Check if the second thing has only 26 chars
//Check if all these chars are letters
//Check for repeated letters

int main(int argc, string argv[])
{
    //Check if user only types two things in terminal
    if (argc == 2)
    {
        int len = strlen(argv[1]);
        
        //Check if user's key only has 26 chars
        if (len != 26)
        {
            printf("Key must have 26 characters.\n");
            return 1;
        }

        int letters[26];
        
        //Check if all those chars are letters
        for (int i = 0; i < len; i++)
        {
            if (isdigit(argv[1][i]) || ispunct(argv[1][i]))
            {
                printf("Key must only contain letters.\n");
                return 1;
            }
            
            //Check for repeated letters
            for (int j = 0; j < 26; j++)
            {
                
                if (argv[1][i] == letters[j])
                {
                    printf("All letters must be different.\n");
                    return 1;
                }
            }
            letters[i] = argv[1][i];
        }
        
        //Declare some variables that will be needed for "translation"
        string plaintext = get_string("plaintext: ");
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        char ciphertext[strlen(plaintext) + 1];
        
        //Start a for loop to go through each char of the plaintext
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            //If that character is lowercase, initiate another for loop to go through each
            //letter of the alphabet, once it matches with the letter from the plaintext, store
            //the position of that letter in the alphabet and get the same position but in the key.
            //Once it gets the position in the key, it forces that letter to be lowercase.
            if (islower(plaintext[i]) != 0)
            {
                for (int m = 0; m < 26; m++)
                {
                    if (plaintext[i] == (alpha[m]))
                    {
                        ciphertext[i] = tolower(argv[1][m]);
                        break;
                    }
                }
            }
            
            //Same process but for uppercases
            else if (isupper(plaintext[i]) != 0)
            {
                for (int m = 0; m < 26; m++)
                {
                    if (plaintext[i] == toupper(alpha[m]))
                    {
                        ciphertext[i] = toupper(argv[1][m]);
                        break;
                    }
                }
            }
            
            //If it is not a letter, then it must be a number or a punctuation, which we want to preserve
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }
        //Had to add a '\0' because it was giving an error in check50 as not a valid ASCII char
        ciphertext[strlen(plaintext)] = '\0';
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
    
    //If user doesn't type only 2 things in terminal
    else
    {
        printf("Usage: ./substitution key.\n");
        return 1;
    }
}
