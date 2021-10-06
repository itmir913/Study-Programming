"""
2741 : 게임 중독
"""


def main():
    alphabet = list("abcdefghijklmnopqrstuvwxyz")
    mystr = list(input())
    crypto = input()

    for a in crypto:
        print(alphabet[mystr.index(a)], end="")


main()

