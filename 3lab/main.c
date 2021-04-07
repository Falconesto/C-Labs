#include <stdio.h>

int main() {
    int x, a, c, d;
    {
        scanf("%d", &x);
        printf("%x\n", x);
        printf("%x << 4 == %x\n", x, x << 4);
        printf("%x\n", x);
        printf("%x\n", ~(x));
    }
    {
        scanf("%x", &a);
        printf("%x & %x = %x\n", x, a, a & x);
    }

    return 0;
}