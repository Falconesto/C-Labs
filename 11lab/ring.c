#include "ring.h"
#include "math.h"

float ringPerimeter(struct Ring ring) {
    float perimeter = 2 * M_PI * (ring.r1 + ring.r2);
    return perimeter;
}

float ringArea(struct Ring ring) {
    float area = M_PI * (pow(ring.r1, 2) - pow(ring.r2, 2));
    return area;
}