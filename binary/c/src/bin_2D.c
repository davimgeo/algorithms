#include <stdio.h>
#include <stdlib.h>

#define BINARY_WRITE "wb"
#define BINARY_READ "rb"

void write2D(const char* FILE_PATH, void* arr, size_t type, int row, int column) 
{
    /*
     * This function writes/create a 2D binary file
     *
     * Input:
     *  const char* FILE_PATH: path to the output binary file 
     *  void* arr: an array of any type (like int/float/double etc)
     *  size_t type: sizeof(type of your choice)
     *  int row: row size of void* arr
     *  int column: column size of void* arr
     *
     * Output:
     *  file.bin
     *
     * Example:
     *
     * >>> int arr[3][3] = {
     *         {1, 2, 3},
     *         {4, 5, 6},
     *         {7, 8, 9}
     * };
     * >>> write2D("data/data.bin", arr, sizeof(int), 3, 3);
    */
    FILE* bin_data = fopen(FILE_PATH, BINARY_WRITE); 
    if (bin_data == NULL) 
    {
        printf("Could not open the file.\n");
        exit(-1);
    }

    fwrite(arr, type, row * column, bin_data); 

    fclose(bin_data);   
}

void read2D(const char* FILE_PATH, void* arr, size_t type, int row, int column)
{
    /*
     * This function reads an 2D binary file into a 2D array
     *
     * Input:
     *  const char* FILE_PATH: path to the input binary file
     *  void* arr: an array of a type of your choise (like int/float/double etc)
     *  size_t type: sizeof(type of your choice)
     *  int row: row size of the binary file (you need to know this beforehand)
     *  int column: column size of binary file (you need to know this beforehand)
     *
     * Output:
     *  arr filled with the bin file information
     *
     * Example:
     *
     * >>> int ROW = 648, COLUMN = 1150;
     * >>> float* arr = (float*)malloc(ROW * COLUMN * sizeof(float));
     * >>> read2D = ("data/data.bin", arr, sizeof(float), ROW, COLUMN);
    */
    FILE* bin_data = fopen(FILE_PATH, BINARY_READ);
    if (bin_data == NULL) 
    {
        printf("Could not open the file.\n");
        exit(-1);
    }

    fread(arr, type, row * column, bin_data); 

    fclose(bin_data);  
}

