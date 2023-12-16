#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        //iterate through column
        for (int j = 0; j < width; j++)
        {
            // turning into grayscale
            int greyscale = round( (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = greyscale;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
     for (int i = 0; i < height; i++)
    {
        //iterate through column
        for (int j = 0; j < width; j++)
        {
            // turning into sepia
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)
    {
        //iterate through column
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // iterate through rows and columns
    for (int i = 0; i < height; i++)
    {
        //iterate through columns
        for (int j = 0; j < width; j++)
        {
            float red = 0;
            float green = 0;
            float blue = 0;
            float counter = 0;

            // iterate through pixels around current pixel i x and y axis:
            for (int x = -1; x < 2; x++)
                {
                for (int y = -1; y < 2; y++)
                    {
                        // check if out of bounds
                        if (i + x < 0 || i + x > height - 1)
                        {
                            continue;
                        }
                        if (j + y < 0 || j + y > width - 1)
                        {
                            continue;
                        }

                        // store the RGB value
                        blue += image[i + x][j + y].rgbtBlue;
                        green += image[i + x][j + y].rgbtGreen;
                        red += image[i + x][j + y].rgbtRed;

                        counter++;
                    }
                }

                // store RGB value in temp matrix
                temp[i][j].rgbtBlue = round(blue / counter);
                temp[i][j].rgbtGreen = round(green / counter);
                temp[i][j].rgbtRed = round(red / counter);
        }
    }

    // this must be a separate loop - so original values remain intact!
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}
