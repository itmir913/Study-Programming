"""
2609 : 최대공약수와 최소공배수
"""


def gcm(a, b):
    if a % b == 0:
        return b
    else:
        return gcm(b, a % b)


def main():
    n, m = map(int, input().split())

    GCM = gcm(n, m)
    LCM = n * m // GCM

    print(GCM)
    print(LCM)


main()
