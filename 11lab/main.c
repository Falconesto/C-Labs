#include "stdio.h"
#include "ring.h"

int main()
{
    struct Ring ring;
    scanf("%f", &ring.r1);
    scanf("%f", &ring.r2);
    printf("Perimeter: %f\n", ringPerimeter(ring));
    printf("Area: %f\n", ringArea(ring));
    return 0;
}