import sys

N = int("".join(sys.stdin.readline().split()))
num = list(map(int, sys.stdin.readline().split()))

for i in range(1, N):
  #새로 시작하냐 vs 계속 더하냐
  num[i] = max(num[i-1] + num[i], num[i])

print(max(num))