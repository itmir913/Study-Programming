# 2017 : 진법 변환

import sys

alphabet = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
            'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

n, k = map(int, sys.stdin.readline().split())
result = []

if n == 0:
    result.append(str(0))
else:
    while n > 0:
        n, sub = divmod(n, k)
        result.append(str(alphabet[sub]))

result.reverse()
for a in result:
    print(a, end='')

