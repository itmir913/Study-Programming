import sys
import string

# input
opcode = sys.stdin.readline().rstrip()
stack = []
priority = {'+': 1, '-': 1, '*': 2, '/': 2, '(': 0}

for s in opcode:
    if s in string.ascii_uppercase:
        print(s, end='')
    else:
        if s == '(':
            stack.append(s)
        elif s == ')':
            pop = ''
            while stack:
                pop = stack.pop()
                if pop == '(':
                    break
                print(pop, end='')
        elif len(stack) == 0:
            stack.append(s)
        else:
            # 스택의 최상단에 있는 연산자가 현재 연산자보다 우선순위가 작을 때까지 계속 반복해야 +가 중간에 있음
            # A+B*C-D/E
            # ABC*+DE/-
            while stack and priority[s] <= priority[stack[-1]]:
                print(stack.pop(), end='')
            stack.append(s)

while stack:
    print(stack.pop(), end='')
