import sys


class BinaryHeap:
    def __init__(self, size):
        self.size = size
        self.array = [None]

    def __len__(self):
        return len(self.array) - 1  # 리스트의 0번 인덱스는 사용하지 않음

    def _percolate_up(self):  # 부모 노드와 자리 바꾸기
        i = len(self)
        parent = i // 2

        while parent > 0:
            if self.array[i] < self.array[parent]:
                self.array[i], self.array[parent] = self.array[parent], self.array[i]  # swap
            else:
                break

            i = parent
            parent = i // 2

    def _percolate_down(self, idx):
        left = idx * 2
        right = idx * 2 + 1
        smallest = idx

        if left <= len(self) and self.array[left] < self.array[smallest]:
            smallest = left

        if right <= len(self) and self.array[right] < self.array[smallest]:
            smallest = right

        if smallest != idx:
            self.array[idx], self.array[smallest] = self.array[smallest], self.array[idx]  # swap
            self._percolate_down(smallest)

    def insert(self, n):
        self.array.append(n)
        self._percolate_up()

    def extract(self):
        extracted = self.array[1]  # 루트 값 추출
        self.array[1] = self.array[len(self)]  # 가장 마지막 노드를 루트 노드 자리에 위치
        self.array.pop()
        self._percolate_down(1)
        return extracted

    def is_empty(self):
        return self.__len__() == 0


n = int(sys.stdin.readline())
heap = BinaryHeap(1100)
for _ in range(n):
    heap.insert(int(sys.stdin.readline()))

while not heap.is_empty():
    print(heap.extract())
