#include "vector.h"
#include "math.h"

coordinate sumVector(coordinate vector_a, coordinate vector_b)
{
    return (coordinate) {vector_a.x+vector_b.x,vector_a.y+vector_b.y};
}

double lengthVector(coordinate vector)
{
    return sqrt(pow(vector.x,2)+pow(vector.y,2));
}