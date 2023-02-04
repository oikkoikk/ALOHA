import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())

computers = [[] for _ in range(N+1)]
ans = []
maxCnt = 1


def BFS(start):

    visited = [False for _ in range(N+1)]
    Q = deque([start])

    visited[start] = True
    cnt = 1

    while Q:
        now = Q.popleft()

        for next in computers[now]:
            if not visited[next]:
                Q.append(next)
                visited[next] = True
                cnt += 1

    return cnt


for i in range(M):
    A, B = map(int, sys.stdin.readline().split())
    computers[B].append(A)

for i in range(1, N+1):
    cnt = BFS(i)

    if cnt < maxCnt:
        continue
    elif cnt > maxCnt:
        ans.clear()
        maxCnt = cnt
    ans.append(i)

print(*ans)
