import sys
from collections import deque

readline = sys.stdin.readline

N, M = map(int, readline().split())
field = []
visited = [[False] * N for _ in range(M)]
dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]
power_b, power_w = 0, 0


def isInside(y, x):
    if 0 <= y < M and 0 <= x < N:
        return True
    return False


def BFS(y, x):
    global power_b, power_w

    visited[y][x] = True
    q = deque()
    q.append([y, x])
    cnt = 1

    while q:
        now_y, now_x = q.popleft()
        for i in range(4):
            next_y = now_y + dir[i][0]
            next_x = now_x + dir[i][1]

            if isInside(next_y, next_x) and field[y][x] == field[next_y][next_x] and not visited[next_y][next_x]:
                visited[next_y][next_x] = True
                q.append([next_y, next_x])
                cnt += 1

    if field[y][x] == 'W':
        power_w += cnt * cnt
    else:
        power_b += cnt * cnt


for i in range(M):
    field.append(list(readline().rstrip()))

for i in range(M):
    for j in range(N):
        if not visited[i][j]:
            BFS(i, j)

print(power_w, power_b)