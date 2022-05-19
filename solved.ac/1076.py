import sys

values = {"black": 0,
          "brown": 1,
          "red": 2,
          "orange": 3,
          "yellow": 4,
          "green": 5,
          "blue": 6,
          "violet": 7,
          "grey": 8,
          "white": 9}

product = {"black": 1 * pow(10, 0),
           "brown": 1 * pow(10, 1),
           "red": 1 * pow(10, 2),
           "orange": 1 * pow(10, 3),
           "yellow": 1 * pow(10, 4),
           "green": 1 * pow(10, 5),
           "blue": 1 * pow(10, 6),
           "violet": 1 * pow(10, 7),
           "grey": 1 * pow(10, 8),
           "white": 1 * pow(10, 9)}

a = sys.stdin.readline().rstrip()
b = sys.stdin.readline().rstrip()
c = sys.stdin.readline().rstrip()

print((values[a] * 10 + values[b]) * product[c])
# print(values[a] * 10 + values[b], end='')

# for _ in range(values[c]):
#     print('0', end='')