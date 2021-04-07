#include <stdio.h>
#include <math.h>


// 2
struct Circle {
    int r;//radius
};

struct Circle CreateCircle(int r) {
    struct Circle cir;
    cir.r = r;
}

float GetCircleArea(struct Circle cir) {
    return cir.r * cir.r * M_PI;
}

int main() {
    // 1
    enum Car {
        Passenger_car,
        Truck,
        Bus,
        Racing_car
    };
    printf("Bus = %d\n", Bus);

    struct Circle cir = CreateCircle(2);
    printf("Площадь круга с радиусом %d равна %f\n", cir.r, GetCircleArea(cir));

    //3
    struct Buttons {
        unsigned NumLock: 1;
        unsigned CapsLock: 1;
        unsigned ScrollLock: 1;
    };
    union Checker {
        unsigned number;
        struct Buttons Status;
    };

    union Checker CheckStatus;
    scanf("%x", &CheckStatus.number);
    printf("NumLock = %d\n", CheckStatus.Status.NumLock);
    printf("CapsLock = %d\n", CheckStatus.Status.CapsLock);
    printf("ScrollLock = %d\n", CheckStatus.Status.ScrollLock);

}