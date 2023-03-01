import sys
import bisect

readline = sys.stdin.readline

N = int(readline().rstrip())
cards = sorted(list(map(int, readline().split())))
M = int(readline().rstrip())
nums = list(map(int, readline().split()))
ans = []

for num in nums:
    res = bisect.bisect_right(cards, num) - bisect.bisect_left(cards,num)
    if res > 0:
        ans.append(1)
    else:
        ans.append(0)

print(*ans)
