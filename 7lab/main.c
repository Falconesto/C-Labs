#include <stdio.h>
#include <math.h>


// 2
struct Triangle {
    int side;
    int height;
};

float GetTriangleArea(struct Triangle my_triangle) {
    return my_triangle.side * my_triangle.height / 2;
}

int main() {
    // 1
    enum Colours {
        Acrylic,
        Oils,
        Latex,
        Silicone
    };
    printf("Oils = %d\n", Oils);
    struct Triangle my_triangle = {3, 4};
    printf("Площадь треугольника со стороной %d и высотой %d равна %f\n", my_triangle.side, my_triangle.height, GetTriangleArea(my_triangle));

    //3
    struct CardReader {
        unsigned SD: 1;
        unsigned CompactFlash: 1;
        unsigned MemoryStick: 1;
    };
    union Checker {
        unsigned number;
        struct CardReader Status;
    };

    union Checker CheckStatus;
    scanf("%hx", &CheckStatus.number);
    printf("NumLock = %d\n", CheckStatus.Status.SD);
    printf("CapsLock = %d\n", CheckStatus.Status.CompactFlash);
    printf("ScrollLock = %d\n", CheckStatus.Status.MemoryStick);

}