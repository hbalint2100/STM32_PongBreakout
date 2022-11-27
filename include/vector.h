#pragma once
#include <stdint.h>

typedef struct coordinate{
    int32_t x, y;
} coordinate;

coordinate sumVector(coordinate vector_a, coordinate vector_b);

double lengthVector(coordinate vector);