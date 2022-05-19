import sys

n, k = map(int, sys.stdin.readline().rstrip().split())

josephus_list = [i for i in range(1, n + 1)]
result = []

index = 0
for _ in range(n):
    index += k - 1
    index %= len(josephus_list)
    result.append(josephus_list.pop(index))

print('<', ', '.join(map(str, result)), '>', sep='')
