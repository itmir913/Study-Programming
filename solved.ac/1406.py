import sys

# 커서를 기준으로 스택을 두 개 만들어서 문제를 해결한다는 발상이다.
# 커서 명령 작업시 front 스택의 마지막과 rear 스택의 첫 item을 각각 append, pop 연산으로 넣어주면 O(1)의 시간복잡도로 마칠 수 있다.

stack_front = list(sys.stdin.readline().rstrip())
stack_rear = []

# 문자열이 abcd라면, 커서의 index는 다음과 같다.
# 0 a 1 b 2 c 3 d 4

for _ in range(int(sys.stdin.readline())):
    token = sys.stdin.readline().split()
    operator = token[0]
    if operator == "L":
        if stack_front:
            stack_rear.append(stack_front.pop())

    elif operator == "D":
        if stack_rear:
            stack_front.append(stack_rear.pop())

    elif operator == "B":
        if stack_front:
            stack_front.pop()

    elif operator == "P":
        stack_front.append(token[1])

print(*stack_front, *reversed(stack_rear), sep='')
