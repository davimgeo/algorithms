#ifndef BIN_2D_H
#define BIN_2D_H

#include <stdio.h>

void write2D(const char* FILE_PATH, void* arr, size_t type, int row, int column);

void read2D(const char* FILE_PATH, void* arr, size_t type, int row, int column);

#endif // BIN_2D_H

