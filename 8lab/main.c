#include <stdio.h>
#include <string.h>

int main(int argc, char **agrv) {
    char str1[100];
    char str2[100];
    int n;


    // Осуществить сравнение символов двух строк
    scanf("%s %s", str1, str2);
    printf("%d  \n", strcmp(str1, str2));

    // Осуществить копирование первых n символов одной строки в другую строку.
    scanf("%s %s %d", str1, str2, &n);
    strncpy(str2, str1, n);
    printf("%s\n", str2);

    //Осуществить поиск длины строки
    scanf("%s", str1);
    printf("%d\n", strlen(str1));

    //Выделить из одной строки лексемы (кусочки), разделенные любым из множества
    //символов (разделителей), входящих во вторую строку.

    char* p;
    scanf("%s %s", str1, str2);
    p = strtok(str1, str2);
    printf("%s", p);
    do {
        p = strtok(NULL, str2);
        if (p) printf("    % s", p);
    } while (p);


    //Осуществить поиск в одной строке любого из множества символов, входящих во вторую строку
    scanf("%s %s", str1, str2);
    printf(" %c\n", *strpbrk(str1, str2));
}