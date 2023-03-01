import sys

readline = sys.stdin.readline


def find(ele):
    if parent[ele] != ele:
        parent[ele] = find(parent[ele])
    return parent[ele]


def union(a, b):
    a = find(a)
    b = find(b)

    if a != b:
      if a < b:
        parent[b] = a
      else:
        parent[a] = b


def search(y, x):
    while(True):
        now_dir = field[y][x]
        now = (x+1) + M*y
        next = 0

        if now_dir == 'D':
            next = now + M
            y += 1
        elif now_dir == 'U':
            next = now - M
            y -= 1
        elif now_dir == 'R':
            next = now + 1
            x += 1
        else:
            next = now - 1
            x -= 1

        if find(now) != find(next):
            union(now, next)
        else:
            return


N, M = map(int, readline().split())
field = []
parent = [i for i in range(N*M+1)]
# 1  2  3  4
# 5  6  7  8
# 9 10 11 12
#field[i][j] = parent[M*i + j+1]
f                                                                 or i in range(N):
    field.append(list(readline().rstrip()))

for i in range(N):
    for j in range(M):
        search(i, j)

print(len(set(parent[1:])))
