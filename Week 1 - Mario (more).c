#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height; 
    
    do
    {
        height = get_int("Height: "); //Asks user for height
    }
    while (height < 1 || height > 8); //Height must be 0 < height < 9
    
    for (int block = 1; block <= height; block++)
    {
        for (int space = height - block; space > 0; space--) //Places spaces before the stairs
        {
            printf(" ");
        }
        for (int stair = 0; stair < block; stair++) //Places stair
        {
            printf("#");
        }
        
        printf("  "); //Spaces the two stairs
        
        for (int stair2 = 0; stair2 < block; stair2++) //Places the second stair
        {
            printf("#");
        }
        //No need to put spaces after second stair
        printf("\n");
    }
    
}
