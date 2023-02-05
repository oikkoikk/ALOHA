import sys
from collections import deque

input = sys.stdin.readline

N = int("".join(input().split()))
square = []
visited = [[False] * N for _ in range(N)]
cnt = 0
householdList = []
dir = [[-1, 0], [0, 1], [1, 0], [0, -1]]  # y x


def isInside(x, y):
    return 0 <= x and x < N and 0 <= y and y < N


def BFS(x, y):
    q = deque()
    q.append([x, y])
    visited[y][x] = True
    households = 1

    while(q):
        nowX, nowY = q.popleft()
        for i in range(4):
            nextX = nowX + dir[i][1]
            nextY = nowY + dir[i][0]
            if isInside(nextX, nextY) and square[nextY][nextX] and not visited[nextY][nextX]:
                visited[nextY][nextX] = True
                q.append([nextX, nextY])
                households += 1

    return households


for i in range(N):
    square.append(list(map(int, input().rstrip())))



for y in range(N):
    for x in range(N):
        if not visited[y][x] and square[y][x]:
            households = BFS(x, y)
            householdList.append(households)
            cnt += 1

print(cnt)
for num in sorted(householdList):
    print(num)
