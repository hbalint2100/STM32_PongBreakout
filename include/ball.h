#pragma once
#include "vector.h"
#define RAD 15

typedef struct ball
{
    coordinate position;
    coordinate direction_vector;
} ball;

void initBall(ball *ball);

void drawBall(ball ball);

void stepBall(ball *ball);

void applyForce(ball *ball, coordinate force);