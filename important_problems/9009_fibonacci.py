import sys
import bisect

readline = sys.stdin.readline

fibo = [1, 1]
T = int(readline().rstrip())

def find(N):
  idx = bisect.bisect_right(fibo, N) - 1
  ans.append(fibo[idx])
  N -= fibo[idx]

  if N == 0:
    return
  find(N)


for i in range(2, 46):
    fibo.append(fibo[i-2]+fibo[i-1])

for _ in range(T):
    N = int(readline().rstrip())
    ans = []

    find(N)
    print(*reversed(ans))


