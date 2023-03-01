import sys

readline = sys.stdin.readline

N = int(readline().rstrip())
MAX = 100001
DP=[MAX]*(MAX) # DP[a] = 금액이 a일 때 동전의 최소 개수
DP[2] = 1
DP[4] = 2
DP[5] = 1

for i in range(6, N+1):
    DP[i] = min(DP[i-2] + 1, DP[i-5] + 1)

if DP[N] >= MAX:
  print("-1")
else:
  print(DP[N])