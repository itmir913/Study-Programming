import sys

# input
n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))

m = int(sys.stdin.readline())
subject_num = list(map(int, sys.stdin.readline().split()))

# algorithm
a.sort()  # 퀵 정렬 등 정렬 알고리즘 수행

for num in subject_num:  # 이진 탐색 등 탐색 알고리즘 수행
    if num in a:
        print('1')
    else:
        print('0')
