class BucketSort:
    def __init__(self, size):
        self.array = [0] * size

    def push_bucket(self, n):
        self.array[n] += 1

    def print_bucket(self):
        for i in range(len(self.array)):
            if self.array[i] > 0:
                for _ in range(self.array[i]):
                    print(i)

    def sorted(self):
        return self.array
