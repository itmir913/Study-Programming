import sys
import string

# input
n = int(sys.stdin.readline())
opcode = sys.stdin.readline().rstrip()

operand = []
stack = []

for _ in range(n):
    operand.append(int(sys.stdin.readline().rstrip()))

for s in opcode:
    if s in string.ascii_uppercase:
        stack.append(operand[string.ascii_uppercase.index(s)])
    else:
        operand_2 = stack.pop()
        operand_1 = stack.pop()

        if s == '+':
            stack.append(operand_1 + operand_2)
        elif s == '-':
            stack.append(operand_1 - operand_2)
        elif s == '*':
            stack.append(operand_1 * operand_2)
        elif s == '/':
            stack.append(operand_1 / operand_2)

print('{:.2f}'.format(round(stack.pop(), 2)))
