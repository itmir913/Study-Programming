# 1165 : 축구의신

import sys

n = int(sys.stdin.readline())

memo = {1: 1, 2: 1}


def fibonacci(n):
    if n in memo:
        return memo[n]

    result = fibonacci(n - 1) + fibonacci(n - 2)
    memo[n] = result
    return result


print(fibonacci(n))

