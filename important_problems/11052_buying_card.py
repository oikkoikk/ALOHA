import sys

N = int("".join(sys.stdin.readline().split()))
prices = [0]
prices.extend(list(map(int, sys.stdin.readline().split())))
DP=[]
DP.extend(prices)
# DP[N] = max(DP[N-1] + DP[1], DP[N-2] + DP[2], DP[N-3] + 3 ... )

for i in range(1, N+1):
  maxVal = 0
  for j in range(0, i):
    maxVal = max(maxVal, DP[i-j] + DP[j])
  DP[i] = maxVal

print(DP[N])



