import sys

readline = sys.stdin.readline
N,M = map(int,readline().split())
parent = [i for i in range(N)]

def find(x):
  if parent[x] != x:
    parent[x] = find(parent[x])
  return parent[x]

def union(a, b):
  a = find(a)
  b = find(b)

  if a == b:
    return True
  else:
    if a > b:
      parent[a] = b
    else:
      parent[b] = a
  return False

for i in range(1,M+1):
  a,b = map(int,readline().split())

  if union(a,b):
    print(i)
    exit()

print(0)
