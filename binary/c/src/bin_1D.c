#include <stdio.h>
#include <stdlib.h>

#define BINARY_WRITE "wb"
#define BINARY_READ "rb"

void write1D(const char* FILE_PATH, void* arr, size_t type, int size) 
{
    /*
     * This function writes/creates a 1D binary file
     *
     * Input:
     *  const char* FILE_PATH: path to the output binary file
     *  void* arr: an array of any type (like int/float/double etc)
     *  size_t type: sizeof(type of your choice)
     *  int size: size of the void* arr
     *
     * Output:
     *  file.bin
     *
     * Example:
     *
     * >>> int arr[] = {1, 2, 3, 4, 5};
     * >>> int size = sizeof(arr) / sizeof(arr[0]);
     * >>> write1D("data/data.bin", arr, sizeof(int), size);
     */
    FILE* bin_data = fopen(FILE_PATH, BINARY_WRITE); 
    if (bin_data == NULL) {
        printf("Could not open the file for writing!\n");
        exit(-1);
    }

    fwrite(arr, type, size, bin_data);  

    fclose(bin_data);   
}

void read1D(const char* FILE_PATH, void* arr, size_t type, int size) 
{
    /*
     * This function reads a 1D binary file
     *
     * Input:
     *  const char* FILE_PATH: path to the input binary file 
     *  void* arr: an array of any type (like int/float/double etc)
     *  size_t type: sizeof(type of your choice)
     *  int size: size of the file you want to read (you need to know this beforehand)
     *
     * Output:
     *  arr filled with the bin file information
     *
     * Example:
     *
     * >>> int size = 15;
     * >>> int* arr = (int*)malloc(size * sizeof(int));
     * >>> read1D("data/data.bin", arr, sizeof(int), size);
     */
    FILE* bin_data = fopen(FILE_PATH, BINARY_READ);
    if (bin_data == NULL) 
    {
        printf("Could not open the file for reading!\n");
        exit(-1);
    }

    fread(arr, type, size, bin_data); 
    fclose(bin_data);  
}

