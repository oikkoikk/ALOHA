import sys

readline = sys.stdin.readline

N = int(readline().rstrip())
arr = list(map(int, readline().split()))
S = int(readline().rstrip())

for i in range(N-1):
    if S==0:
        break
    ele, idx = arr[i], i

    ele = max(arr[i:i+S+1]) #최대한 큰 수를 앞쪽에 놔야하므로
    idx = arr.index(ele)
    S -= idx-i

    for j in range(idx,i,-1):
        arr[j] = arr[j-1]
    arr[i] = ele

print(*arr)