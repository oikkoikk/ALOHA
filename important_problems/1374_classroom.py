import sys
import heapq

readline = sys.stdin.readline

N = int(readline().rstrip())
courses, q = [], []
cnt = 0

for i in range(N):
    num, start, end = map(int, readline().split())
    courses.append((start,end))

courses.sort(key=lambda x: x[0])

for i in courses:
    while q and q[0] <= i[0]:
        heapq.heappop(q) #해당 수업과 같은 강의실을 쓰면 되므로 힙에서 더 이상 필요 X
    heapq.heappush(q, i[1])
    cnt = max(cnt, len(q))

print(cnt)
