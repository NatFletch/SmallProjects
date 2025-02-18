#include "test.h"
#include <time.h>
#include <limits.h>

void run_tests(Vector3* array){
    printf("=====TESTING IN PROGRESS=====\n");
    printf("===PRINTING VECTOR3 ARRAY===\n");

    print_array(array);

    printf("====PERFORMING INITALIZATION FOR VECTOR3 TESTS====\n");

    srand(time(NULL));
    unsigned int random_num_1 = rand() % get_array_length(array);
    unsigned int random_num_2 = UINT_MAX;

    do {
        random_num_2 = rand() % get_array_length(array);
    } while(random_num_2 == random_num_1);

    Vector3 a = array[random_num_1];
    Vector3 b = array[random_num_2];

    printf("====CHOSEN VECTORS:====\n");
    printf("VECTOR A: ");
    print_v3(a);
    printf("VECTOR B: ");
    print_v3(b);

    printf("===FINDING THE CROSS PRODUCT OF TWO VECTORS===\n");

    Vector3 normal = find_cross_product(a, b);
    print_v3(normal);

    printf("===FINDING THE DOT PRODUCT OF TWO VECTORS===\n");

    double magnitude = find_dot_product(a,b);
    printf("A * B = %.2lf\n", magnitude);

    printf("===FINDING THE SCALAR TRIPLE PRODUCT OF TWO VECTORS===\n");

    double magnitude2 = find_scalar_triple_product(normal, a, b);
    printf("NORMAL * (A X B): %.2lf\n", magnitude2);

    printf("====TESTS COMPLETE====\n");
}