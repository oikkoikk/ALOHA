import sys

readline = sys.stdin.readline


def w(a, b, c):
    if a <= 0 or b <= 0 or c <= 0:
        return 1
    if a > 20 or b > 20 or c > 20:
        a, b, c = 20, 20, 20
    if DP[a][b][c]:
        return DP[a][b][c]

    if a < b < c:
        DP[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
    else:
        DP[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + \
            w(a-1, b, c-1) - w(a-1, b-1, c-1)
    return DP[a][b][c]


while True:
    A, B, C = map(int, readline().split())
    DP = [[[0] * 21 for _ in range(21)] for _ in range(21)]
    if (A, B, C) == (-1, -1, -1):
        exit()

    print(f"w({A}, {B}, {C}) = {w(A,B,C)}")
