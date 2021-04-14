#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int initial;
    int final;
    
    // TODO: Prompt for start size
    
    do
    {
        initial = get_int("Initial population: ");
        
        if (initial < 9)
        {
            printf("Population must be at least 9!\n");
        }
    }
    while (initial < 9);

    // TODO: Prompt for end size
    
    do
    {
        final = get_int("Final population: ");
        
        if (final < initial)
        {
            printf("Final population shouldn't be less than initial population!\n");
        }
        if (final == initial)
        {
            printf("Years: 0\n");
        }
    }
    while (final < initial);

    // TODO: Calculate number of years until we reach threshold
    
    int year = 0;
    int i = initial;
    
    do
    {
        i = i + (i / 3) - (i / 4);
        year++;
    }
    while (i < final); // Sums annual growth to initial population until it becomes final population
    
    // TODO: Print number of years
    printf("Years: %i\n", year);
}
