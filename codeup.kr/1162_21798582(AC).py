"""
1162 당신의 사주를 봐 드립니다 1
"""


def main():
    year, month, day = map(int, input().split())

    calc = (year - month + day) % 10
    if calc == 0:
        print("대박")
    else:
        print("그럭저럭")


main()

