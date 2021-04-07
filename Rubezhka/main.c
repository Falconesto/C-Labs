#include <stdio.h>

int main() {
    freopen("brackets.in", "r", stdin);
    fseek(stdin, 0, SEEK_END);
    int n = ftell(stdin);
    int input;
    fseek(stdin, 0, SEEK_SET);
    int situation = 0;
    for (int i = 0; i < n; i++) {
        fread(&input, sizeof(char), 1, stdin);
        if (input == '(') {
            situation++;
            printf("++");
        } else {
        if (input == ')') {
            if(situation>0) {
                situation--;
                printf("--");
            }
            else{
                if(situation<1){
                    printf("Ne vernaya posledovatelnost");
                    return 0;
                }
            }
        }else{
            printf("Proverte vhoddnie dannie");
        }
    }
    }
    if(situation!=0){
        printf("Ne vernaya posledovatelnost");
    }else{
        printf("URA! Vernaya posledovatelnost!");
    }
    return 0;
}