import sys
import itertools

N = int("".join(sys.stdin.readline().split()))

DP = [[1] * 10 for _ in range(N+1)]


# DP[a][b] => a자리 수에 b가 들어오는 오르막 수의 개수
len = 1

while True:
    if len == N+1:
        break

    DP[len] = list(map(lambda x: x % 10007,list(itertools.accumulate(DP[len-1]))))
    len+=1

print(DP[N][9])
