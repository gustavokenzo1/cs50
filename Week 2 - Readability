#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    
    //Asks user for a text
    string text;
    text = get_string("Text: ");
    
    int letters = 0;
    int words = 1; //Use 1 instead of 0 because the last word is followed by a '.' instead of a space
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //Counts the number of letters by looking at the ith character and deciding
        //if it is uppercase or lowercase, if it's neither, it's not a letter
        if (isupper(text[i]) || islower(text[i]))
        {
            letters++;
        }
        
        //According to the ASCII chart, 32 is the number for space, so every space means a new word
        if (text[i] == 32)
        {
            words++;
        }
        
        //Using the ASCII chart again but for punctuation
        if (text[i] == 33 || text[i] == 46 || text[i] == 63) 
        {
            sentences++;
        }

    }
    //Coleman-liau index = 0.0588 * L - 0.296 * S - 15.8
    //L = avg number of letters per 100 words
    //S = avg number of sentences per 100 words
    //Use "Regra de 3" (I don't know the name in English) to determine those avgs
    
    float L = ((float) letters * 100) / (float) words;
    float S = ((float) sentences * 100) / (float) words;
    int index = round(0.0588 * (float) L - 0.296 * (float) S - 15.8);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    
    else
    {
        printf("Grade %i\n", index);
    }
}
