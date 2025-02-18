#include "vector.h"

double _find_determinant(double a, double b, double c, double d){
    return (a*d) - (b*c);
}

Vector3 find_cross_product(Vector3 a, Vector3 b){
    Vector3 vector = {
        _find_determinant(a.y, a.z, b.y, b.z), // i
        -_find_determinant(a.x, a.z, b.x, b.z), // j
        _find_determinant(a.x, a.y, b.x, b.y), // k
    };

    return vector;
}

double find_dot_product(Vector3 a, Vector3 b){
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

double find_scalar_triple_product(Vector3 a, Vector3 b, Vector3 c){
    return find_dot_product(a, find_cross_product(b, c));
}
