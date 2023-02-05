import sys

input = sys.stdin.readline

N = int("".join(input().split()))
DP = [-1] * (5001)
# DP[a] = a kg일 때 봉지의 개수
DP[3] = 1
DP[5] = 1

for i in range(6, N+1):
  if DP[i-3] != -1 and DP[i-5] != -1:
    DP[i] = min(DP[i-3] + 1, DP[i-5] +1)
  elif DP[i-3] != -1:
    DP[i] = DP[i-3] + 1
  elif DP[i-5] != -1:
    DP[i] = DP[i-5] + 1

print(DP[N])
