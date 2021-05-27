#include <stdio.h>

int main(int argc, char **argv) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", (n && !m) || (!n && m)); // 비트 xor 연산자는 ^인데, 논리 xor 연산자는 없는 듯

    return 0;
}

