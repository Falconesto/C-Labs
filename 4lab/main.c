#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    printf("%d \n", x >= 33 && x <= 88);
    int b;
    scanf("%d", &b);
    printf("%d", (b >> 19) % 2);
    return 0;
}