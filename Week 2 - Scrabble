#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
// List of all lowercase letters
// List of all uppercase letters
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int LOWER[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int UPPER[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }

    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }

    // No need for an else condition, since score1 = score2 is the only option
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int score = 0;
    
    // Checks the position of a letter in a word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // If the letter is lowercase, associate it to a letter from the LOWER list,
        // pick it's postion in that list, store that position and pick the
        // equivalent position in the POINTS list and associate it to a score
        if (islower(word[i]))
        {
            for (int j = 0, pos1 = sizeof(LOWER); j < pos1; j++)
            {
                if (word[i] == LOWER[j])
                {
                    score += POINTS[j];
                }
            }

        }
        // Same but different
        else if (isupper(word[i]))
        {
            for (int j = 0, pos2 = sizeof(UPPER); j < pos2; j++)
            {
                if (word[i] == UPPER[j])
                {
                    score += POINTS[j];
                }
            }
        }
    }
    
    return score;

}
