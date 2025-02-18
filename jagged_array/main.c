#include "jagged_array.h"

int main(){
    int** array = NULL;
    int rows = 5;
    int row_lengths[] = {3,5,2,7,6};
    array = create_array(rows, row_lengths);
    print_array(array);
    free_array(array);
    return 0;
}