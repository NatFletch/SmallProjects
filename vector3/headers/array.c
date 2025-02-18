#include "array.h"

#define DATABASE_FILE "Database.txt"

void print_v3(Vector3 vector){
    printf("(x: %.2lf, y: %.2lf, z: %.2lf)\n", vector.x, vector.y, vector.z);
}

Vector3* create_array(unsigned int size){
    Vector3* array = NULL;
    array = malloc(sizeof(Vector3) * size + sizeof(int));

    ((int*)array)[0] = size;
    array = (Vector3*)(((int*)array)+1);
    
    return array;
}

void free_array(Vector3* array){
    array = (Vector3*)(((int*)array)-1);
    free(array);
}

unsigned int get_array_length(Vector3* array){
    return ((int*)array)[-1];
}

void print_array(Vector3* array){
    for(unsigned int i=0; i<get_array_length(array); i++){
        print_v3(array[i]);
    }
}

void fill_array_from_file(Vector3* array){
    FILE* filePtr = NULL;
    filePtr = fopen(DATABASE_FILE, "r");

    if(filePtr == NULL){
        printf("ERROR: Unable to open database file\n");
        return;
    }

    char buffer[255];
    double x, y, z = 0;
    unsigned int counter = 0;

    while(!feof(filePtr)){
        if(fscanf(filePtr, "%lf %lf %lf", &x, &y, &z) == 3 && counter < get_array_length(array)){
            Vector3 new_vector = {x, y, z};
            array[counter] = new_vector;
            fgets(buffer, 255, filePtr); // go to the next line
            counter++;
        }
    }

    fclose(filePtr);
}