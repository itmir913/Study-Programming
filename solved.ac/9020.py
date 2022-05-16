# 백준 9020 골드바흐의 추측

import sys


def binary_search(list, n):  # n보다 크지 않은 최대 소수를 구함
    low = 0
    high = len(list) - 1

    while low <= high:  # 같거나 가장 큰 소수 이진 검색하기
        mid = (low + high) // 2
        if list[mid] == n:
            return mid
        elif list[mid] < n:
            low = mid + 1
        else:
            high = mid - 1

    return high  # 최댓값 인덱스 반환


prime_list = []
hash_table = [False] * (10000 + 1)
hash_table[0] = False
hash_table[1] = False

filter = [False] * (10000 + 1)
for i in range(2, 10000 + 1):
    if filter[i]:
        continue

    hash_table[i] = True
    prime_list.append(i)
    for j in range(i * 2, 10000 + 1, i):  # 에라토스테네스의 체
        filter[j] = True

del filter

# input
n = int(sys.stdin.readline().rstrip())
for _ in range(n):
    result_1, result_2 = 0, 0
    diff = -1

    a = int(sys.stdin.readline().rstrip())
    max_prime_index = binary_search(prime_list, a)

    # 해시테이블 돌리기

    for i in range(max_prime_index, 0 - 1, -1):
        prime = prime_list[max_prime_index]

        if prime * 2 == a:
            result_1 = result_2 = prime
            diff = 0
            break

        minus = a - prime
        if minus > prime:
            continue

        if hash_table[minus]:
            if diff == -1 or (prime - minus) < diff:
                diff = prime - minus
                result_2 = prime
                result_1 = minus

        max_prime_index -= 1

    print(result_1, result_2)
