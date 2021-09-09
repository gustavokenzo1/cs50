#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string plaintext;
    string ciphertext;

    //Check if the user only types 2 "words" in terminal
    if (argc == 2)
    {
        //If the user types 2 "words" and it contains a letter, it will be invalid
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        //Transforms string to an int
        int key = atoi(argv[1]);
        
        //If that key is a negative number, it's invallid
        //Might be useless, since the negative digit isn't a number
        //but it's good to take notes
        if (key < 0)
        {
            printf("Usage: ./caesar key\n");
        }

        //"For loop" to go through each letter of the key
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            //If every digit is a number, it's a valid key and it should go on
            //and ask for the message
            if (isdigit(argv[1][i]))
            {
                plaintext = get_string("plaintext: ");
                char c;
                printf("ciphertext: ");

                //"For loop" to go through each char of the message
                for (int j = 0, m = strlen(plaintext); j < m; j++)
                {
                    c = plaintext[j];
                    
                    //If it's a letter, it will separate into uppercase and lowercase
                    //and then use the key to translate to another letter
                    if (isalpha(c))
                    {
                        if (isupper(c))
                        {
                            c = (((c + key) - 65) % 26 + 65);
                            printf("%c", c);
                        }
                        
                        else if (islower(c))
                        {
                            c = (((c + key) - 97) % 26 + 97);
                            printf("%c", c);
                        }
                        
                    }
                    
                    //If it's not a letter (i.e.: number, punctuation etc), it won't do anything
                    else
                    {
                        printf("%c", c);
                    }
                }
                printf("\n");

                return 0;
            }
        }
    }
    //If the user doens't write two "words" in the terminal, it will give the error message
    else
    {
        printf("Usage: ./caesar key");
        return 1;
    }
}
