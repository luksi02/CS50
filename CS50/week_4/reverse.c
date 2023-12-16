#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Check command-line arguments
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./recover INPUT.wav OUTPUT.wav \n");
        return 1;
    }

    // Open input file for reading
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open file %s.\n", argv[1]);
        return 2;
    }

    // Read header
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, inptr);

    // Use check_format to ensure WAV format
    if (check_format(header) != 0)
    {
        printf("Not a Wave file\n");
        return 3;
    }

    if(header.audioFormat != 1)
    {
        printf("Not a Wave File.\n");
        return 4;
    }

    // Open output file for writing
    FILE *outptr = fopen(argv[2], "w");
    if (outptr == NULL)
    {
        printf("Could not open file.\n");
    }

    // Write header to file
    fwrite(&header, sizeof(WAVHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    int size = get_block_size(header);

    // Write reversed audio to file
    (fseek(inptr, size, SEEK_END));

    BYTE buffer[size];
    while(ftell(inptr) - size > sizeof(header))
    {
        fseek(inptr, - 2 * size, SEEK_CUR);
        fread(buffer, size, 1, inptr);
        fwrite(buffer, size, 1, outptr);
    }

    fclose(inptr);
    fclose(outptr);
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 5;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    int size = header.numChannels * header.bitsPerSample / 8;
    return size;
}
