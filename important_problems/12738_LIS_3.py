import sys
import bisect

readline = sys.stdin.readline

N = int(readline().rstrip())
cards = list(map(int, readline().split()))
DP=[]

for num in cards:
  if len(DP)==0 or num > DP[-1]:
    DP.append(num)
  else:
    DP[bisect.bisect_left(DP,num)] = num

print(len(DP))
