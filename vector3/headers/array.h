#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
    double z;
} Vector3;

void print_v3(Vector3 vector);

Vector3* create_array(unsigned int size);
void free_array(Vector3* array);
unsigned int get_array_length(Vector3* array);
void print_array(Vector3* array);
void fill_array_from_file(Vector3* array);

#endif