# Python Template

import sys

# input
n = sys.stdin.readline()
a, b = map(int, sys.stdin.readline().split())

# string format
print("{} {}".format(10, 20))

# 1 in [1, 2]
# 1 not in [1, 2]


# list
l = [1, 2, 3]

len(l)
l.append(4)
l.insert(0, 5)
l.extend([6, 7, 8])
ll = l + [1, 2, 3]

del l[0]
l.pop(0)

index, value = enumerate(list)

# dictionary
dictionary = {"A": 10, "B": 20}
A = dictionary["A"]
dictionary["New"] = 30

# memoization
memo = {1: 1, 2: 1}


def fibonacci(n):
    if n in memo:
        return memo[n]

    result = fibonacci(n - 1) + fibonacci(n - 2)
    memo[n] = result
    return result


# lambda function
power = lambda x: x * x

# with file open
with open("text.txt", "w") as file:
    for line in file:
        # 파일 한 줄씩 읽기
        pass
    pass

# try - catch - finally
try:
    pass
except Exception as ex:
    # raise NotImplementedError
    pass  # 예외 처리 코드
else:
    pass  # 예외가 발생하지 않았을 때 처리
finally:
    pass  # 무조건 실행


# private val : start with __


# getter setter with decorator
class Circle:
    __radius = 0

    @property
    def radius(self):
        return self.__radius

    @radius.setter
    def radius(self, value):
        if value <= 0:
            raise TypeError("radius is bigger then 0")
        self.__radius = value


# map
map(lambda x: x * x, [1, 2, 3])

# filter
filter(lambda x: x < 3, [1, 2, 3])
