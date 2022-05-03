import sys


def GCD(a, b):
    if b == 0:
        return a
    else:
        return GCD(b, a % b)


# input
n = int(sys.stdin.readline())

for _ in range(n):
    a, b = map(int, sys.stdin.readline().split())
    print(int(a * b / GCD(a, b)))
