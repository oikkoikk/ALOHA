import sys
import math

T = int(input())
for _ in range(T):
    N = input()
    logs = sorted(map(int, sys.stdin.readline().split()))

    ans = []

    ans.append(logs.pop(0))

    for i in range(len(logs)):
        # 배열 앞뒤로 넣어주기
        ans.insert(math.ceil(len(ans)/2), logs[i])

    gap = abs(ans[len(ans)-1] - ans[0])

    for i in range(len(ans)-1):
        gap = max(gap, abs(ans[i+1] - ans[i]))

    print(gap)
