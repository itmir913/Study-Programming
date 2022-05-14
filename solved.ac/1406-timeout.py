# 시간 초과

import sys

editor = list(sys.stdin.readline().rstrip())
cursor = len(editor)  # 커서는 문장의 맨 뒤

# 문자열이 abcd라면, 커서의 index는 다음과 같다.
# 0 a 1 b 2 c 3 d 4

n = int(sys.stdin.readline())
for _ in range(n):
    token = sys.stdin.readline().split()
    operator = token[0]
    if operator == "L":
        if cursor > 0:
            cursor -= 1

    elif operator == "D":
        if cursor < len(editor):
            cursor += 1

    elif operator == "B":
        if cursor > 0:
            cursor -= 1
            del editor[cursor]

    elif operator == "P":
        editor.insert(cursor, token[1])
        cursor += 1

print(*editor, sep='')
