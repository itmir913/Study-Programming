#include <stdio.h>

int main(void) {
    int height[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d", &height[i]);
    }

    int my_car = 170;
    int check = 0;
    for (int i = 0; i < 3; ++i) {
        if (my_car >= height[i]) {
            printf("CRASH %d", height[i]);
            check = 1;
            break;
        }
    }

    if (check == 0) {
        printf("PASS");
    }

    return 0;
}
