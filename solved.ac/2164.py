import sys
from collections import deque

# input
n = int(sys.stdin.readline().rstrip())
deque = deque()

for i in range(1, n + 1):
    deque.append(i)

while len(deque) > 1:
    deque.popleft()
    deque.append(deque.popleft())

print(deque.pop())
