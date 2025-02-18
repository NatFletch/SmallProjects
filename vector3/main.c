#include "headers/array.h"
#include "headers/vector.h"
#include "headers/test.h"

int main(){
    Vector3* array = NULL;
    unsigned int size = 8;

    array = create_array(size);
    fill_array_from_file(array);

    run_tests(array);

    free_array(array);
    return 0;
}