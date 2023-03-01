import sys

readline = sys.stdin.readline


def Combination(n, r):
    r = min(r, n-r)
    numer = 1
    denom = 1

    for i in range(r):
        numer *= (n-i)
        denom *= (r-i)

    return numer//denom


N = int(readline().rstrip())
tree = [[] for _ in range(N+1)]
edges = []
d_cnt, g_cnt = 0, 0
for i in range(N-1):
    u, v = map(int, readline().split())
    tree[u].append(v)
    tree[v].append(u)
    edges.append([u, v])

for edge in edges:
    d_cnt += (len(tree[edge[0]])-1) * (len(tree[edge[1]])-1)

for i in range(1, N+1):
    if len(tree[i]) >= 3:
        g_cnt += Combination(len(tree[i]), 3)

if d_cnt > 3 * g_cnt:
    print("D")
elif d_cnt < 3 * g_cnt:
    print("G")
elif d_cnt == 3 * g_cnt:
    print("DUDUDUNGA")
