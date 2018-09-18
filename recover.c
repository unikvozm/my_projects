#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover imagefile\n");
        return 1;
    }

    // open input file
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    unsigned char buffer[512];
    int i = 0; //number of images recovered

    //open output files
    FILE *img = NULL;

    //array for filename is 8 for "000.jpg"
    char filename[8];

    while (fread(buffer, 512, 1, inptr) != 0)
    {
        //already found a JPEG?
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            //start of a new JPEG?
            if (img != NULL)
            {
                fclose(img);
            }
            //start writing pictures
            sprintf(filename, "%0.3d.jpg", i);
            img = fopen(filename, "a");
            fwrite(&buffer, 512, 1, img);
            i++;
        }

        else
        {
            if (img != NULL)
            {
                fwrite(&buffer, 512, 1, img);
            }
        }
    }
    //close files
    fclose(inptr);
    fclose(img);

    //success
    return 0;
}