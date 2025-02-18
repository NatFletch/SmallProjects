#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Production prototypes
int** create_array(int rows, int* row_lengths);
int get_num_rows(int** array);
int get_row_length(int** array, int row);
int fill_array(int** array);
int free_array(int** array);

// Debug prototypes
void print_array(int** array);

#endif