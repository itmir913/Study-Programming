# 3708: nCr (Large)

import sys

n, r = map(int, sys.stdin.readline().split())

memo = {0: 1,
        1: 1}


def factorial(n):
    if n in memo:
        return memo[n]
    elif n - 1 in memo:
        result = (memo[n - 1] * n)
        memo[n] = result
        return result

    result = 1
    for x in range(1, (n) + 1):
        if x in memo:
            result = memo[x]
            continue
        else:
            result = (result * x)
            memo[x] = result

    return result


nCr = (factorial(n) // (factorial(r) * factorial(n - r))) % 100000007
print(nCr)

