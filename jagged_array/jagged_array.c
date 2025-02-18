#include "jagged_array.h"

#define DEBUG_MODE 0

int** create_array(int rows, int* row_lengths){
    // Create and initalize an array
    int** array = NULL;
    array = malloc(rows * sizeof(int*) + sizeof(int*)); // x number of rows plus an extra for storing row number

    // Put the row number in array and increment pointer
    ((int*)array)[0] = rows;
    array = (int**)(((int*)array)+1);

    if(DEBUG_MODE == 1){
        printf("Initialized 2D array with %d rows\n", get_num_rows(array));
    }

    // Allocate all the rows
    for(int i=0; i<get_num_rows(array); i++){
        array[i] = malloc(row_lengths[i] * sizeof(int) + sizeof(int)); // allocate x amount of slots plus an extra for row length
        array[i][0] = row_lengths[i];
        array[i] = (int*)(((int**)array)[i]+1);
    }

    if(DEBUG_MODE == 1){
        printf("Allocated all of the rows with the following sizes: ");
        for(int i=0; i<get_num_rows(array); i++){
            printf("%d ", get_row_length(array, i));
        }
        printf("\n");
    }

    // Fill the array with random numbers
    int fill_status = fill_array(array);

    if(DEBUG_MODE == 1 && fill_status == 0){
        printf("Successfully filled the array with random numbers\n");
    }

    return array;
}

// Gets the number of rows in an array
int get_num_rows(int** array){
    return ((int*)array)[-1];
}

// Gets the length of a specified row
int get_row_length(int** array, int row){
    return array[row][-1];
}

// Fills the array with random numbers
int fill_array(int** array){
    // Set the seed for the random number generator
    srand(time(NULL));

    for(int i=0; i<get_num_rows(array); i++){
        for(int j=0; j<get_row_length(array, i); j++){
            array[i][j] = rand() % 100;
        }
    }

    return 0;
}

int free_array(int** array){
    // Free all rows first
    for(int i=0; i<get_num_rows(array); i++){
        array[i]--;
        free(array[i]);
        array[i] = NULL;
    }

    array = (int**)(((int*)array)-1);
    free(array);
    array = NULL;
    return 0;
}

void print_array(int** array){
    for(int i=0; i<get_num_rows(array); i++){
        for(int j=0; j<get_row_length(array, i); j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}