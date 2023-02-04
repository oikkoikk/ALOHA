import sys
from collections import deque

input = sys.stdin.readline

N = int("".join(input().split()))
people = [[]]
rumor = [-1] * (N+1)


def distribute(distributors):
    global rumor
    distributors = deque(distributors)
    dq = deque()

    while distributors:
        person = distributors.popleft()

        for neighbor in people[person]:
            cnt = 0
            if rumor[neighbor] != -1:  # 이미 루머가 퍼진 상태
                continue
            for i in people[neighbor]:
                if rumor[i] != -1:
                    cnt += 1
            if cnt * 2 >= len(people[neighbor]):
                dq.append(neighbor)

        if not distributors:  # 한 사이클이 끝나면
            while dq:
                temp = dq.popleft()
                rumor[temp] = rumor[person] + 1
                distributors.append(temp)

    rumor = rumor[1:]


for i in range(N):
    temp = list(map(int, input().split()))
    people.append(temp[:-1])

M = int("".join(input().split()))

distributors = list(map(int, input().split()))
for distributor in distributors:
    rumor[distributor] = 0

distribute(distributors)

print(*rumor)
