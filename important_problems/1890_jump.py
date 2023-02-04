import sys

N = int("".join(sys.stdin.readline().split()))
board = []
DP = [[0] * N for _ in range(N)]
# DP[a][b] = (a,b)에 올 수 있는 경우의 수

for i in range(N):
    board.append(list(map(int, sys.stdin.readline().split())))

for i in range(N):
    for j in range(N):
        if i == 0 and j == 0:
            DP[0][0] = 1
            continue
        for k in range(1, j+1):
            if board[i][j-k] == k:
                DP[i][j] += DP[i][j-k]
        for k in range(1, i+1):
            if board[i-k][j] == k:
                DP[i][j] += DP[i-k][j]

print(DP[N-1][N-1])
