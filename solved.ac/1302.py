import sys

# input
n = int(sys.stdin.readline().rstrip())
dict = {}

for i in range(n):
    inp = sys.stdin.readline().strip()
    if inp in dict:
        dict[inp] += 1
    else:
        dict[inp] = 1

max_ = max(dict.values())
array = []
for key, value in dict.items():
    if value == max_:
        array.append(key)

array.sort()
print(array[0])
