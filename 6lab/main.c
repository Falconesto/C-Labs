#include <stdio.h>
#include <malloc.h>

int main()
{
    int *a; //адрес
    int mas[4];
    a = mas;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &mas[i]);
    }
    for (int i = 0; i < 4; i++) {
        printf("%d ", *(a + i));
    }

    float *b;
    int i;
    b = (int*)malloc(4 * sizeof(int)); //что это, размер
    for (i = 0; i<4; i++)
    {
        scanf("%d", &b[i]);
    }
    for (i = 0; i<4; i++)
        printf("%d ",b[i]);
    free(b); //что это
    return 0;
}