#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
     for (int i = 0; i < height; i++)
    {
        //iterate through column
        for (int j = 0; j < width; j++)
        {
            //if pixel is black, then convert pixels into X colour
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                image[i][j].rgbtRed = 100;
                image[i][j].rgbtBlue = 255;
                image[i][j].rgbtGreen = 100;
            }
            //if pixel is white, convert pixels to X colour
            else
            {
                image[i][j].rgbtRed = 96;
                image[i][j].rgbtBlue = 69;
                image[i][j].rgbtGreen = 200;
            }
        }
    }
}
