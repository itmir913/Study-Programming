import sys

num = int(sys.stdin.readline())

stack = []

for _ in range(num):
    token = sys.stdin.readline()
    list_token = token.split()
    if "push" == list_token[0]:
        operand = list_token[1]
        stack.append(operand)
    elif "pop" == list_token[0]:
        if len(stack) == 0:
            print("-1")
        else:
            print(stack.pop())
    elif "size" == list_token[0]:
        print(len(stack))
    elif "empty" == list_token[0]:
        if len(stack) == 0:
            print("1")
        else:
            print("0")
    elif "top" == list_token[0]:
        if len(stack) == 0:
            print("-1")
        else:
            print(stack[-1])
