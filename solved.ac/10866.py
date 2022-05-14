import sys


class DequeUsingCircleQueue:

    def __init__(self, max_size):
        self.front_index = 0
        self.rear_index = 0
        self.queue = [0] * max_size
        self.max_size = max_size

    def push_front(self, n):
        if self.is_full():
            raise Exception("FULL QUEUE")
        self.queue[self.front_index] = n
        self.front_index = (self.front_index - 1 + self.max_size) % self.max_size

    def push_back(self, n):
        if self.is_full():
            raise Exception("FULL QUEUE")
        self.rear_index = (self.rear_index + 1) % self.max_size
        self.queue[self.rear_index] = n

    def pop_front(self):
        if self.empty():
            # raise Exception("EMPTY QUEUE")
            return -1
        self.front_index = (self.front_index + 1) % self.max_size
        return self.queue[self.front_index]

    def pop_back(self):
        if self.empty():
            # raise Exception("EMPTY QUEUE")
            return -1
        temp = self.queue[self.rear_index]
        self.rear_index = (self.rear_index - 1 + self.max_size) % self.max_size
        return temp

    def size(self):
        count = 0
        temp_front = self.front_index
        while True:
            if temp_front == self.rear_index:
                break
            count += 1
            temp_front = (temp_front + 1) % self.max_size
        return count

    def is_full(self):
        if (self.rear_index + 1) % self.max_size == self.front_index:
            return True
        return False

    def empty(self):
        if self.front_index == self.rear_index:
            return True
        return False

    def front(self):
        if self.empty():
            return -1
        return self.queue[(self.front_index + 1) % self.max_size]  # 가장 앞

    def back(self):
        if self.empty():
            return -1
        return self.queue[self.rear_index]  # 가장 뒤


# input
num = int(sys.stdin.readline())
queue = DequeUsingCircleQueue(20000)

for _ in range(num):
    token = sys.stdin.readline()
    token_list = token.split()

    if "push_front" == token_list[0]:
        operand = token_list[1]
        queue.push_front(operand)
    elif "push_back" == token_list[0]:
        operand = token_list[1]
        queue.push_back(operand)
    elif "pop_front" == token_list[0]:
        print(queue.pop_front())
    elif "pop_back" == token_list[0]:
        print(queue.pop_back())
    elif "size" == token_list[0]:
        print(queue.size())
    elif "empty" == token_list[0]:
        if queue.empty():
            print('1')
        else:
            print('0')
    elif "front" == token_list[0]:
        print(queue.front())
    elif "back" == token_list[0]:
        print(queue.back())
