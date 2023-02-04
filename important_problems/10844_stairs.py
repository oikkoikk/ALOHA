import sys

N = int("".join(sys.stdin.readline().split()))

DP = [[0] * 10 for _ in range(N+1)]
# DP[a][b] a자리에 b가 들어가는 계단 수의 개수

for i in range(1, 10):
    DP[1][i] = 1

for i in range(2, N+1):
    for j in range(10):
        if j == 0:
            DP[i][j] = DP[i-1][1] % 1000000000
        elif j == 9:
            DP[i][j] = DP[i-1][8] % 1000000000
        else:
            DP[i][j] = DP[i-1][j-1] + DP[i-1][j+1] % 1000000000

print(sum(DP[N]) % 1000000000)
