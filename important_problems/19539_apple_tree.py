import sys

input = sys.stdin.readline

N = int("".join(input().split()))
trees = list(map(int, input().split()))

sum = sum(trees)
two = 0

for tree in trees:
    two += tree // 2

if sum % 3 or sum//3 > two:
    # 1. 나무 높이의 총합은 3의 배수여야 함
    # 2. 2를 부을 수 있는 횟수 < 전체 일수 => 1을 더 많이 부어야 한다? -> 불가능!
    #    (2를 부을 수 있으면, 1도 부을 수 있다 ∴2를 기준으로 체크!)
    print("NO")
else:
    print("YES")
