#include "helpers.h"
#include <math.h>
// Convert image to grayscale
// All filters should use the same process of a nested loop, that iterates through the 2D array

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Get the value of each color of pixel[h][w]
            int r = image[h][w].rgbtRed;
            int g = image[h][w].rgbtGreen;
            int b = image[h][w].rgbtBlue;

            // Averages those numbers and rounds to the nearest integer
            int avg = round(((float) r + (float) g + (float) b) / 3);

            // For a pixel to be a variation of gray, R, G and B should have the same value
            image[h][w].rgbtRed = avg;
            image[h][w].rgbtGreen = avg;
            image[h][w].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Create ints with the same name of the formula given because I'm lazy
            int originalGreen = image[h][w].rgbtGreen;
            int originalRed = image[h][w].rgbtRed;
            int originalBlue = image[h][w].rgbtBlue;

            // Formula but rounded
            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            // If the value surpasses 255, it should be 255, which is the MAX
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // If it doesn't, then good I guess...
            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
// Loop should go only till half of the image, since we're switching first value with last value and so forth

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            // temp will store all RGB values for pixel[h][w]
            RGBTRIPLE temp = image[h][w];

            // example to follow: 0, 1, 2, 3, 4, 5, 6
            image[h][w] = image[h][width - (w + 1)];
            image[h][width - (w + 1)] = temp;
        }
    }
    return;
}

// Blur image
// Pixel color should be the average of all surrounding pixels
// Special cases: edges
// Edges could mean:
// h & w = 0
// h = 0
// w = 0
// h = height
// w = width
// h & w = height & width
// Create a temporary picture? Because when we change one pixel, it will affect when changing the others
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Create 4 loops, one to iterate through each row, one to each colllum, one to every surrounding pixel of i'th pixel in that row and the same for the collum
    // This should go through every pixel and it´s surroundings
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // Initiate variables to store information about each color and how many pixels where used
            int totalBlue = 0;
            int totalRed = 0;
            int totalGreen = 0;
            float pixels = 0;

            for (int h = -1; h < 2; h++)
            {
                for (int w = -1; w < 2; w++)
                {
                    // If the pixel we are in is less than 0 or is greater then the image's height, it doesn't exist and we should just ignore it
                    if ((i + h) < 0 || (i + h) > (height - 1))
                    {
                        continue;
                    }

                    // Same goes for the collums
                    if ((j + w) < 0 || (j + w) > (width - 1))
                    {
                        continue;
                    }

                    // If there is a pixel, get it's value from the copied image and update the variables
                    totalBlue += copy[i + h][j + w].rgbtBlue;
                    totalRed += copy[i + h][j + w].rgbtRed;
                    totalGreen += copy[i + h][j + w].rgbtGreen;
                    pixels++;
                }
            }
            // After getting all the values from the copied image, we can find the avg and pass it into the original image
            image[i][j].rgbtBlue = round(totalBlue / pixels);
            image[i][j].rgbtRed = round(totalRed / pixels);
            image[i][j].rgbtGreen = round(totalGreen / pixels);

        }
    }
}
