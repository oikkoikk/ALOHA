import sys

readline = sys.stdin.readline

N, K = map(int, readline().split())
DP = [[0] * (N+1) for _ in range(N+1)]
DP[0][0] = 1
DP[1][0] = 1
DP[1][1] = 1

for i in range(2, N+1):
    for j in range(i+1):
        if j == 0:
            DP[i][j] = 1
        else:
            DP[i][j] = DP[i-1][j] + DP[i-1][j-1]

print(DP[N][K] % 10007)