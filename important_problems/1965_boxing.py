import sys
import bisect

readline = sys.stdin.readline

N = int(readline().rstrip())
boxes = map(int,readline().split())
ans=[]

for box in boxes:
  if not ans or ans[-1] < box:
    ans.append(box)
    continue
  ans[bisect.bisect_left(ans,box)] = box

print(len(ans))
  