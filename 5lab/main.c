#include <stdio.h>

int main() {
    int a[6];
    int i;
    for (i = 0; i < 6; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    }

    int arr1[2][2] = {{1, 1}, //поменять матрицу на единичную
                      {1, 4}};
    int arr2[2][2] = {{1, 2},
                      {4, 1}};
    int res[2][2] = {0};
    for (i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j)
            printf("\n A[%d][%d]= %d", i, j, res[i][j]);
    }

    return 0;
}