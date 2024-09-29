#ifndef BIN_1D_H
#define BIN_1D_H

#include <stdio.h>

void write1D(const char* FILE_PATH, void* arr, size_t type, int size);

void read1D(const char* FILE_PATH, void* arr, size_t type, int size);

#endif // BIN_1D_H

