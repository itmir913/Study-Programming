import sys

# input
n = int(sys.stdin.readline().rstrip())


def test(str):
    stack = []
    for s in str:
        if s == '(':
            stack.append(True)
        elif s == ')' and len(stack) > 0:
            stack.pop()
        else:
            return False

    if len(stack) == 0:
        return True

    return False


for _ in range(n):
    print("YES" if test(sys.stdin.readline().rstrip()) else "NO")
