#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct Point {
    double x;
    double y;
};

double Distance(struct Point *point1, struct Point *point2) {
    double x1 = point1->x;
    double x2 = point2->x;
    double y1 = point1->y;
    double y2 = point2->y;
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double **getArray(struct Point *point, int n) {
    double **array;
    array = (double **) malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        *(array + i) = (double *) malloc((n - 1) * sizeof(double));
        int j1 = 0;
        for (int j = 0; j < n - 1; j++) {
            if (i == j) {
                j1++;
            }
            *(*(array + i) + j) = Distance(point + i, point + j1);
            j1++;
        }
    }
    return array;
}


char *clear(char *s) {
    int n = (int)strlen(s);
    for(int i = 1; i < n; i++) {
        if((s[i] == ' ') && ((s[i - 1] == ' ') || (s[i - 1] == '{') || (s[i - 1] == '[') || (s[i - 1] == '('))) {
            int k = 0;
            int j = i;
            if (i < n - 1)
                while (s[j] == ' ' && s[j + 1] == ' ') {
                    j++;
                    k++;
                }
            char *res = clear(s + i + 1 + k);
            strcpy(s + i, res);
            return s;
        }
    }
    return s;
}



int main() {
    //5 задача
    char arr[100] = "";
    char *ch;
    ch = gets(arr);
    printf("%s\n", clear(arr));

    //2 задача
    int n;
    scanf("%d", &n);
    double **newArray;
    newArray = (double **) malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        *(newArray + i) = (double *) malloc((n - 1) * sizeof(double));
    }
    struct Point *p;
    p = (struct Point *) malloc(n * sizeof(struct Point));
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &((p + i)->x), &((p + i)->y));
    }
    newArray = getArray(p, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            printf("%lf ", *(*(newArray + i) + j));
        }
        printf("\n");
    }
}