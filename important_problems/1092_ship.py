import sys
import bisect

readline = sys.stdin.readline

N = int(readline().rstrip())
crains = sorted(list(map(int, readline().split())))
M = int(readline().rstrip())
boxes = sorted(list(map(int, readline().split())))
shipped = [0] * len(boxes)
maxIdx = [0] * len(crains)
time = 0

if boxes[-1] > crains[-1]:
    print(-1)
    exit()

for i in range(len(crains)):
    maxIdx[i] = bisect.bisect_right(boxes, crains[i]) -1

while maxIdx[-1] >= 0:
    time += 1
    for i in range(len(maxIdx)):
        while maxIdx[i] >= 0 and shipped[maxIdx[i]] > 0:
            maxIdx[i] -= 1
        if maxIdx[i] < 0:
            continue
        shipped[maxIdx[i]] = time

print(max(set(shipped)))
