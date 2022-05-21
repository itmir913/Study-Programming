import sys
import heapq  # 최소 힙이므로 최대 힙을 구현할 때는 -를 붙여야 한다.

# input
n = int(sys.stdin.readline().rstrip())
heap_plus = []  # 최소 힙: 양수는 절대값이 작을수록 최소
heap_minus = []  # 최대 힙: 음수는 절대값이 작을수록 최대

for _ in range(n):
    i = int(sys.stdin.readline().rstrip())
    if i > 0:
        heapq.heappush(heap_plus, i)
    elif i < 0:
        heapq.heappush(heap_minus, -i)
    else:
        len_plus = len(heap_plus)
        len_minus = len(heap_minus)

        if len_plus == 0 and len_minus == 0:
            print(0)
            continue
        elif len_plus == 0:
            print(-heapq.heappop(heap_minus))
            continue
        elif len_minus == 0:
            print(heapq.heappop(heap_plus))
            continue

        abs_plus = abs(heap_plus[0])
        abs_minus = abs(heap_minus[0])

        if abs_plus == abs_minus:
            print(-heapq.heappop(heap_minus))
        elif abs_plus < abs_minus:
            print(heapq.heappop(heap_plus))
        else:
            print(-heapq.heappop(heap_minus))
