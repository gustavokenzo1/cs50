#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Included string.h to use the strcmp

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    // For loop to iterate through each candidate
    // If the name the voter wants matches the name of a candidate it will == 0, indicating true for strcmp
    // Then, it will update the preferences of that voter, putting candidate i in rank position
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    // Two for loops, one to loop through each voter and the other for each candidate
    // if that candidate hasn't been eliminated, update the votes.
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int p = preferences[i][j];
            if (candidates[p].eliminated == false)
            {
                candidates[p].votes = candidates[p].votes + 1;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    // Total voters can be either an odd or an even number of people
    // If it is even, more than half shoud be half + 1
    // If it is odd, we can +1 the number to make it even and then divide it by 2
    // If a candidate surpasses more than half, he is immediately considered a winner
    int votes_needed;

    if (voter_count % 2 == 0)
    {
        votes_needed = (voter_count / 2) + 1;
    }

    if (voter_count % 2 != 0)
    {
        votes_needed = (voter_count + 1) / 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > votes_needed - 1)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
// Similar process to the one done in plurality exercise
// Had to add the eliminated status
int find_min(void)
{
    // TODO
    int last = voter_count;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < last && candidates[i].eliminated == false)
        {
            last = candidates[i].votes;
        }
    }
    return last;
}

// Return true if the election is tied between all candidates, false otherwise
// For loop to iterate through each candidate
// If the candidate has the minimum amount of votes and isn't eliminated yet, both variables +1
// If he has more than the minimum amount of votes, he isn't eliminated
// If the amount of people who weren't eliminate yet == candidates with minimum votes, it's a tie
bool is_tie(int min)
{
    // TODO
    int not_eliminated = 0;
    int tied = 0;
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            not_eliminated++;
            tied++;
        }
        
        else if (candidates[i].votes > min && candidates[i].eliminated == false)
        {
            not_eliminated++;
        }
    }
    if (not_eliminated == tied)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
// For loop to iterate through each candidate
// If the candidates has the same amount of minimum votes, he/she is eliminated
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
