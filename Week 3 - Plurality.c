#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    // Iterate through all candidates of the struct
    // If the name the user typed matches the name of the candidate, the "stringcompare" function
    // Should be 0, indicating that it's true
    // When it's true, it will update the vote count for that ith candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // Declare an int for starters
    int winner = 0;
    
    for (int i = 0; i < candidate_count; i++)
    {
        // Everytime the candidate has more votes than that integer, the integer becomes
        // the total votes of that candidate. This means the winner integer will always store
        // the highest number of votes, including if two candidates receive the highest number of votes
        if (candidates[i].votes > winner)
        {
            winner = candidates[i].votes;
        }
    }
    
    for (int i = 0; i < candidate_count; i++)
    {
        // Now that the winner integer has a value, the loop will go again through each candidate
        // and print out the candidates whose votes are the same as the winner integer
        if (candidates[i].votes == winner)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
