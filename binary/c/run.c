#include <stdio.h>
#include <stdlib.h>
#include "src/include/bin_2d.h"

#define ROW 648
#define COLUMN 1150

int main(int argc, char *argv[])
{
    const char* FILE_PATH = "data/model_vp_2d.bin";
    const char* OUTPUT_TXT = "data/model_vp_2d.txt"; 

    // Reading a 2D bin file

    float* arr_2dr = (float*) malloc(ROW * COLUMN * sizeof(float));
    if (arr_2dr == NULL) 
    {
        printf("Could not allocate enough memory!\n");
        exit(-1);
    }

    read_2D(FILE_PATH, arr_2dr, sizeof(float), ROW, COLUMN);

    // Converting 2D array into a txt

    FILE *file_out = fopen(OUTPUT_TXT, "w");
    if (file_out == NULL) 
    {
        printf("Could not open the file!\n");
        exit(-1);
    }

    // saving in the format column-major used in Fortran
    for (int j = 0; j < COLUMN; ++j) 
    {
        for (int i = 0; i < ROW; ++i) 
        {
            fprintf(file_out, "%f ", arr_2dr[i * COLUMN + j]);
        }
        fprintf(file_out, "\n"); 
    }

    fclose(file_out);
    free(arr_2dr);  
    return 0;
}

