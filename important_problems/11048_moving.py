import sys

N, M = tuple(map(int, sys.stdin.readline().split()))

maze = [[0] * (M+1) for _ in range(N+1)]
DP = [[0] * (M+1) for _ in range(N+1)]
# DP[a][b] = (a,b)에 도착했을 때 보유한 사탕 개수의 최댓값

for i in range(1, N+1):
    maze[i] = list(map(int, sys.stdin.readline().split()))
    maze[i].insert(0,0)


for i in range(1, N+1):
    for j in range(1, M+1):
        DP[i][j] = max(DP[i-1][j], DP[i][j-1], DP[i-1][j-1]) + maze[i][j]

print(DP[N][M])
