import sys
import heapq
readline = sys.stdin.readline

N = int(readline().rstrip())
nums = list(map(int, readline().split()))
# 0과 5, 1과 4, 2와 3이 대칭
# 1면만 보이는 주사위 : 4*(N-2)*(N-1) + (N-2)*(N-2)
# 2면만 보이는 주사위 : 4*(N-1) + 4*(N-2)
# 3면만 보이는 주사위 : 4
ans = 0
small_nums = []

for i in range(3):
    side_1, side_2 = nums[i], nums[5-i]
    small_nums.append(min(side_1,side_2))
small_nums.sort()

if N > 1:
    ans += small_nums[0] * (4 * (N-1) * (N-2) + (N-2) ** 2)
    ans += (small_nums[0] + small_nums[1]) * (4*(N-1) + 4*(N-2))
    ans += (small_nums[0] + small_nums[1] + small_nums[2]) * 4
else:
    ans = sum(heapq.nsmallest(5, nums))

print(ans)
