import sys
import heapq
readline = sys.stdin.readline

INF = 1000000001


def Dijkstra(start, fin):
    q = []
    heapq.heappush(q, (-INF, start))

    while q:
        now_weight, now_island = heapq.heappop(q)
        now_weight = -now_weight

        if max_weight[now_island] < INF:
            continue
        max_weight[now_island] = min(now_weight, max_weight[now_island])

        if now_island == fin:
            return
        for island, weight in bridges[now_island]:
            heapq.heappush(q, (-min(weight, max_weight[now_island]), island))


N, M = map(int, readline().split())
bridges = [[] for _ in range(N+1)]
max_weight = [INF] * (N+1)

for i in range(M):
    a, b, c = map(int, readline().split())
    bridges[a].append((b, c))
    bridges[b].append((a, c))
st, fn = map(int, readline().split())

for i in range(1, N + 1):
    bridges[i].sort(reverse=True)

Dijkstra(st, fn)

print(max_weight[fn])
