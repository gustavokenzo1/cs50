#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check if user only typed two arguments in command line
    if (argc != 2)
    {
        printf("Usage: ./recover file\n");
        return 1;
    }
    
    // input is a file that was opened to read from what user typed 
    FILE *input = fopen(argv[1], "r");
    
    // If what user typed doesn't match a file, it gives an error message
    if (input == NULL)
    {
        printf("File does not exist\n");
        return 1;
    }
    
    // Buffer is composed of 512 bytes
    BYTE buffer[512];
    
    // Count images for naming later
    int count = 0;
    
    // Create an output file that is empty for now
    FILE *output = NULL;
    
    // Filename has 8 bytes, because of the format ###.jpg\0
    char filename[8];
    
    // Loop to read from input into buffer 512 bytes at a time
    while (fread(buffer, 512, 1, input) != 0)
    {
        
        // JPGs start with the same first 3 bytes, and thank god for brian for the fourth byte
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Name the file
            sprintf(filename, "%03i.jpg", count);
            
            // Output will now be opened and be file filename
            output = fopen(filename, "w");
            
            // Increase count
            count++;
        }
        
        // If there is an output, write from buffer into it
        if(output != NULL)
        {
            fwrite(buffer, 512, 1, output);
        }
    }
    
    // Close everything
    fclose(input);
    fclose(output);
}
