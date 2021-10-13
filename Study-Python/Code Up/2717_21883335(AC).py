# 2717: 분수의 합

import sys


def gcd(a, b):
    n = a % b
    if n == 0:
        return b
    return gcd(b, n)


n = int(sys.stdin.readline())
fraction = []
product = 1

for x in range(n):
    fraction.append(list(map(int, sys.stdin.readline().split())))
    product *= fraction[x][1]

for value in fraction:
    p = product // value[1]
    value[0] *= p
    value[1] *= p

result = [0, fraction[0][1]]
for value in fraction:
    result[0] += value[0]

result_gcd = gcd(result[0], result[1])
result[0] //= result_gcd
result[1] //= result_gcd

print("{}/{}".format(result[0], result[1]))

