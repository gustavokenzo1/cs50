#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float cash;
    
    do
    {
        cash = get_float("Change amount: "); //Asks user for amount of change in dollars
    }
    while (cash <= 0);
    
    int change = round(cash * 100); //Converts dollars into cents
    int coins = 0;
    
    while (change >= 25) //Repeats the process till change becomes less than coin value
    {
        coins++;
        change = change - 25;
    }
    
    while (change >= 10) //Analogue
    {
        coins++;
        change = change - 10;
    }
    
    while (change >= 5) //Analogue
    {
        coins++;
        change = change - 5;
    }
    
    while (change >= 1) //Analogue
    {
        coins++;
        change = change - 1;
    }
    
    printf("Change owed: %d\n", coins); //Prints optimal amount of coins
}
