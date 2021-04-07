#include <stdio.h>

int main() {

    int minutes;
    float costDefault, costOfMinute, costTotal;
    printf("Кол-во минут затраченых: \n");
    scanf("%d", &minutes);
    printf("Абонентская плата: \n");
    scanf("%f", &costDefault);
    printf("Плата за каждую следующую минуту: \n");
    scanf("%f", &costOfMinute);
    if (costOfMinute<=499/costDefault) {
        printf("Введите ПРАВИЛЬНУЮ плату за каждую следующую минуту: \n");
        scanf("%f", &costOfMinute);
    }
    if (minutes<500) {
        costTotal=costDefault;
    }else{
        costTotal=costDefault+(minutes-499)*costOfMinute;
    }
    printf("За этот месяц надо будет заплатить %.2f;\n\n\n", costTotal);


    int k, months;
    float sum, percent;
    printf("Кол-во месяцев: \n");
    scanf("%d", &months);
    printf("Процентная ставка: \n");
    scanf("%f", &percent);
    printf("Изначальная сумма на счете: \n");
    scanf("%f", &sum);
    for (k = 1; k < months + 1; k++) {
        sum = sum + sum * percent / 100;
        printf("После %d месяцев на счете будет %.2f;\n", k, sum);
    }

    return 0;
}