// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize f infile outfile\n");
        return 1;
    }

    // remember filenames and a factor
    float f = atof(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    //checking the factor
    if ((f <= 0) || (f > 100))
    {
        fprintf(stderr, "The factor must be (0.00; 100.0]\n");
        return 1;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // determine padding for scanlines in infile
    int padding_in = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // create outfile's BITMAPFILEHEADER and BITMAPINFOHEADER
    BITMAPFILEHEADER out_bf = bf;
    BITMAPINFOHEADER out_bi = bi;

    //changing outfile's headers
    out_bi.biWidth = floor(out_bi.biWidth * f);
    out_bi.biHeight = floor(out_bi.biHeight * f);
    int padding_out = (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    out_bi.biSizeImage = (sizeof(RGBTRIPLE) * out_bi.biWidth + padding_out) * abs(out_bi.biHeight);
    out_bf.bfSize = (out_bi.biSizeImage + sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER));

    // write outfile's BITMAPFILEHEADER
    fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    if (f >= 1)
    {
        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
            for (int q = 0; q < floor(f); q++)
            {
                //send infile's cursor to the beginning
                fseek(inptr, sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER) + (bi.biWidth * sizeof(RGBTRIPLE) + padding_in) * i, SEEK_SET);

                // iterate over pixels in scanline
                for (int j = 0; j < bi.biWidth; j++)
                {
                    // temporary storage
                    RGBTRIPLE triple;

                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                    // write RGB triple to outfile
                    for (int g = 0; g < floor(f); g++)
                    {
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }
                }

                // skip over padding, if any
                fseek(inptr, padding_in, SEEK_CUR);

                // then add it back (to demonstrate how)
                for (int k = 0; k < padding_out; k++)
                {
                    fputc(0x00, outptr);
                }
            }
        }
    }

    else
    {
        int l = 0;
        while (l < abs(bi.biHeight))
        {
            // iterate over pixels in scanline
            int m = 0;
            while (m < bi.biWidth)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

                m += floor(bi.biWidth / out_bi.biWidth);
            }

            // skip over padding, if any
            fseek(inptr, padding_in, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < padding_out; k++)
            {
                fputc(0x00, outptr);
            }

            l += floor(bi.biHeight / out_bi.biHeight);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
