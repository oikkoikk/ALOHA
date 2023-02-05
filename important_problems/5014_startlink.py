import sys
from collections import deque

readline = sys.stdin.readline

F, S, G, U, D = map(int, readline().split())
MAX = 987654321
DP = [MAX] * (F+1)  # DP[a] = a층을 가는데 눌러야 할 버튼의 최솟값


def BFS(cnt, now):
    DP[now] = cnt
    q = deque()
    q.append(now)

    while(q):
        now = q.popleft()
        if now == G:
            return
        if now + U <= F and DP[now+U] > DP[now] + 1:
            DP[now+U] = DP[now]+1
            q.append(now+U)
        if now - D >= 1 and DP[now-D] > DP[now] + 1:
            DP[now-D] = DP[now]+1
            q.append(now-D)


BFS(0, S)

if DP[G] == MAX:
    print("use the stairs")
else:
    print(DP[G])
