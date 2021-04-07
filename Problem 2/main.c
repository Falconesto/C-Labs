#include <stdio.h>
#include <math.h>

int main (void)
{
    double m, n;
    scanf("%lf", &m);
    scanf("%lf", &n);
    printf ("First problem : %.25f\n", ((m-1)*sqrt(m)-(n-1)*sqrt(n))/(sqrt(pow(m, 3)*n)+m*n+pow(m, 2)-m));
    printf ("Second problem : %.25f\n", (sqrt(m)-sqrt(n))/m );
    return 0;
}