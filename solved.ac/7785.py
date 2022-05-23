import sys

logs = set()

n = int(sys.stdin.readline().rstrip())
for _ in range(n):
    name, log = map(str, sys.stdin.readline().rstrip().split())
    if log == "enter":
        logs.add(name)
    elif log == "leave":
        logs.remove(name)

result = list(logs)
result.sort(reverse=True)
for name in result:
    print(name)
