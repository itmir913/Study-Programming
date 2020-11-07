#include <stdio.h>

int main(int argc, char **argv) {
    /**
     * 입력 값의 범위가 -2147483648 ~ +2147483647 이므로 long long int로 받아준다.
     */
    long long int n;
    scanf("%lld", &n);
    printf("%lld", ++n);

    return 0;
}
