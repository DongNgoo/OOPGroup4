//
// File Reading:
// - More complex situation with an optional field
//   that is in the middle of the data
// - Uses comma (,) delimited fields
// - field 2 is an optional C string!
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define DATA_FILE "data.txt"

#define STR_LEN 20
#define INV_SIZE 5

struct Product
{
    int sku;
    char description[STR_LEN + 1];
    double price;
};

int main(void)
{
    struct Product inv[INV_SIZE] = { {0} };
    FILE* fp = fopen(DATA_FILE, "r");
    char tmpChar, tmpDesc[STR_LEN + 1] = { 0 };
    int i = 0;

    if (fp != NULL)
    {
        while (i < INV_SIZE && 
               fscanf(fp, "%d,", &inv[i].sku) == 1)
        {
            // now determine if there is a description field
            // if there is a description, the next char will not
            // be a comma delimiter!
            tmpChar = fgetc(fp);
            // No description!
            if (tmpChar == ',')
            {
                // Make sure source array element description
                // member is set to empty:
                inv[i].description[0] = '\0';
                // Read in the price field
                fscanf(fp, "%lf\n", &inv[i].price);
            }
            else
            {
                // Read in the remaining description part and price field
                // NOTE: we've already read 1 char, so we only want to permit
                //       a max of 19 in the remaining chars to read
                //       "read up to but not including the , delimeter":
                if (fscanf(fp, "%19[^,],%lf\n", tmpDesc, &inv[i].price) == 2)
                {
                    // Make sure we store the read char of 
                    // the description to the source array element description
                    // member:
                    inv[i].description[0] = tmpChar;
                    inv[i].description[1] = '\0'; // set a null byte for concatenation later!

                    // now append the remaining read-in description to the 
                    // array member description field
                    strcat(inv[i].description, tmpDesc);
                }
                else
                {
                    // if we get here, there was an error; most likely the C string
                    // was too long... so let's "eat" the extra chars until a newline
                    // and move on to the next record..
                    // OR: you can try to find the delimiter and attempt to get the price
                    //     but it is unknown exactly where this read failed
                    // ** Works very similarly as the clear input buffer function! **
                    while (fgetc(fp) != '\n');  // discarding data until the end of the line

                    // now let's mark this record as corrupted so we know in the resulting
                    // data that it is an error:
                    strcpy(inv[i].description, "*Error*");
                }
            }

            // don't forget to increment the indexer!
            i++;
        }

        // Clean up!
        fclose(fp);
        fp = NULL;

        // Display results:
        for (i = 0; i < INV_SIZE; i++)
        {
            if (inv[i].sku > 0)
            {
                printf("ID: %d  NAME: %-10.10s  GRADE: %.1lf\n",
                       inv[i].sku, inv[i].description, inv[i].price);
            }
        }
    }
    else
    {
        puts("ERROR: Unable to open file.");
    }

    return 0;
}