import sys
import heapq

readline = sys.stdin.readline
INF = int(1e8)


def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    dist[start] = 0

    while q:
        d, now = heapq.heappop(q)

        if d > dist[now]:
            continue

        for i in graph[now]:
            cost = d + i[1]

            if cost < dist[i[0]]:
                dist[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

N, D = map(int, readline().split())
dist = [INF] * (D+1)
graph = [[] for _ in range(D+1)]

for i in range(D):
    graph[i].append((i+1, 1))

for i in range(N):
    st, fn, d = map(int, readline().split())
    if fn > D:
        continue
    graph[st].append((fn, d))

dijkstra(0)

print(dist[D])
