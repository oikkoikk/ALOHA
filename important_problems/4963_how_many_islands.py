import sys
from collections import deque

dir = [[0, 1], [1, 1], [1, 0], [1, -1],
       [0, -1], [-1, -1], [-1, 0], [-1, 1]]  # x y
W = 0
H = 0
cnt = 0


def isInside(x, y):
    return 0 <= x and x < W and 0 <= y and y < H


def BFS(x, y):
    Q = deque()

    Q.append([x, y])
    visited[y][x] = True

    while(Q):
        now = Q[0]
        Q.popleft()

        for i in range(len(dir)):
            nextX = now[0] + dir[i][0]
            nextY = now[1] + dir[i][1]
            if isInside(nextX, nextY) and world[nextY][nextX] == 1 and not visited[nextY][nextX]:
                Q.append([nextX, nextY])
                visited[nextY][nextX] = True


while(True):
    W, H = map(int, input().split())
    cnt = 0

    if (W, H) == (0, 0):
        exit()

    world = [[0] * W for _ in range(H)]
    visited = [[False] * W for _ in range(H)]

    for y in range(H):
        world[y] = list(map(int, sys.stdin.readline().split()))

    for y in range(H):
        for x in range(W):
            if not visited[y][x] and world[y][x] == 1:
                BFS(x, y)
                cnt += 1
    print(cnt)
