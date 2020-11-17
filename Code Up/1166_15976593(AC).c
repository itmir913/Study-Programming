#include <stdio.h>

int year_function(int year);

int main(int argc, char **argv) {
    int year;
    scanf("%d", &year);

    switch (year_function(year)) {
        case 1:
            printf("yes");
            break;
        case 0:
            printf("no");
    }

    return 0;
}

int year_function(int year) {
    if (year % 4 == 0 && year % 100 != 0) {
        return 1;
    } else if (year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}
