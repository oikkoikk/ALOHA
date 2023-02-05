import sys

input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
ans = []
aLen, bLen = len(A), len(B)


def merge(aPointer, bPointer):
    while aPointer != aLen or bPointer != bLen:
        if aPointer == aLen:
            ans.extend(B[bPointer:])
            bPointer += bLen-bPointer
        elif bPointer == bLen:
            ans.extend(A[aPointer:])
            aPointer += aLen - aPointer
        else:
            if A[aPointer] < B[bPointer]:
                ans.append(A[aPointer])
                aPointer += 1
            else:
                ans.append(B[bPointer])
                bPointer += 1

merge(0,0)

print(*ans)