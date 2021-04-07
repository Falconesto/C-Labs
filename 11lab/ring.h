#ifndef H_RING
#define H_RING
#include "math.h"

struct Ring
{
    float r1;
    float r2;
};

float ringPerimeter(struct Ring ring);
float ringArea(struct Ring ring);
#endif