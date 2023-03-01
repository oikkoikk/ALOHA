import sys

readline = sys.stdin.readline

N = int(readline().rstrip())

T, P, DP = [], [], [0]*(N+1)
# DP[a] = a일까지의 최대이익

for i in range(N):
    t, p = map(int, readline().split())

    T.append(t)
    P.append(p)

for i in range(0,N):
    for j in range(i+T[i], N+1):
      if DP[j] < DP[i] + P[i]:
        DP[j] = DP[i] + P[i]

print(DP[N])
