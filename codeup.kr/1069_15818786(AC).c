﻿#include <stdio.h>

int main(int argc, char **argv) {
    char n;
    scanf("%c", &n);

    switch (n) {
        case 'A':
            printf("best!!!");
            break;
        case 'B':
            printf("good!!");
            break;
        case 'C':
            printf("run!");
            break;
        case 'D':
            printf("slowly~");
            break;
        default:
            printf("what?");
            break;
    }

    return 0;
}
