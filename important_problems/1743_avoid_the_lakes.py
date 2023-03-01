import sys
from collections import deque

readline = sys.stdin.readline


def isInside(y, x):
    if 0 < y <= N and 0 < x <= M:
        return True
    return False


def BFS(y, x):
    global maxCnt

    q = deque()
    visited[y][x] = True
    q.append((y, x))
    cnt = 0

    while q:
        now_y, now_x = q.popleft()
        cnt+=1
        for i in range(4):
            next_x = now_x + dir[i][0]
            next_y = now_y + dir[i][1]

            if isInside(next_y, next_x) and not visited[next_y][next_x] and hallway[next_y][next_x]:
                visited[next_y][next_x] = True
                q.append((next_y, next_x))
    maxCnt = max(cnt, maxCnt)

N, M, K = map(int, readline().split())
hallway = [[0] * (M+1) for _ in range(N+1)]
visited = [[False] * (M+1) for _ in range(N+1)]
dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]
maxCnt = 0

for i in range(K):
    r, c = map(int, readline().split())
    hallway[r][c] = 1

for i in range(1, N+1):
    for j in range(1, M+1):
        if not visited[i][j] and hallway[i][j]:
            BFS(i, j)

print(maxCnt)