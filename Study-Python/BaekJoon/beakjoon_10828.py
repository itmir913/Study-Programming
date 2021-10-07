# 10828 스택
import sys

num = int(sys.stdin.readline())

stack = []

for _ in range(num):
    token = sys.stdin.readline()
    if "push" in token:
        operand = token.split()[1]
        stack.append(operand)
    elif "pop" in token:
        if len(stack) == 0:
            print("-1")
        else:
            print(stack.pop())
    elif "size" in token:
        print(len(stack))
    elif "empty" in token:
        if len(stack) == 0:
            print("1")
        else:
            print("0")
    elif "top" in token:
        if len(stack) == 0:
            print("-1")
        else:
            print(stack[-1])
