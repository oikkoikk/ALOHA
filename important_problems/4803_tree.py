import sys
readline = sys.stdin.readline


def dfs(node):
    visited[node] = True
    for adj in graph[node]:
        if parent[node] == adj:
            continue #부모노드로 역주행 패스
        if visited[adj]:
            return True #사이클!

        parent[adj] = node
        if dfs(adj):
            return True
    return False


tc = 0
while True:
    tc += 1
    N, M = map(int, readline().split())

    if [N, M] == [0, 0]:
        break

    graph = [[] for _ in range(N+1)]
    parent = [i for i in range(N+1)]
    visited = [False] * (N+1)
    cnt = 0  # 트리의 개수

    for _ in range(M):
        a, b = map(int, readline().split())
        graph[a].append(b)
        graph[b].append(a)

    for node in range(1, N+1):
        if not visited[node] and not dfs(node):
            cnt += 1

    print(f"Case {tc}: ", end="")
    if cnt == 0:
        print("No trees.")
    elif cnt == 1:
        print("There is one tree.")
    else:
        print(f"A forest of {cnt} trees.")
