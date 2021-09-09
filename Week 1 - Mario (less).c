#include <stdio.h>
#include <cs50.h>

int main(void)

{
    int height;
    
    //Gets user's desired height
    do 
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    //Makes a stair with that height
    
    for (int block = 1; block <= height; block++)
    {
        for (int dot = height - block; dot > 0; dot--) //Spaces out till it reaches the right collum
        {
            printf(" ");
        }
        for (int row = 0; row < block; row++)
        {
            printf("#");
        }
        printf("\n");
    }
    
    
 
}
