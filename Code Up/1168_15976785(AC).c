#include <stdio.h>

int age_calc(int birth, int current_year);

int main(int argc, char **argv) {
    int birth, gender;
    scanf("%d %d", &birth, &gender);

    int year = birth / 10000;
//    printf("%.2d", year);

    switch (gender) {
        case 1:
        case 2:
            printf("%d", age_calc(1900 + year, 2012));
            break;
        case 3:
        case 4:
            printf("%d", age_calc(2000 + year, 2012));
            break;
    }

    return 0;
}

int age_calc(int birth, int current_year) {
    return current_year - birth + 1;
}
