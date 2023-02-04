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
    # 2. 2를 부울 수 있는 횟수 < 전체 일수 => 애초에 불가능
    print("NO")
else:
    print("YES")
