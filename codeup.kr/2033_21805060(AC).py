"""
2033: 사다리게임
"""


def main():
    k, n = map(int, input().split())

    connected = []
    for a in range(n):
        connected.append(list(map(int, input().split())))

    start = int(input())
    location = start

    for line in connected:
        if location not in line:
            continue

        index = line.index(location)

        if index == 0:
            location = line[1]
        elif index == 1:
            location = line[0]

    print(location)


main()

