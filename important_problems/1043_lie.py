import sys

readline = sys.stdin.readline

N, M = map(int, readline().split())
temp = list(map(int, readline().split()))
numTruth = 0
peopleTruth = []
peopleParties = []
parent = [i for i in range(N+1)]
ans = 0


def find(a):
    if parent[a] != a:
        parent[a] = find(parent[a])
    return parent[a]


def union(a, b):
    a = find(a)
    b = find(b)

    if a < b:  # a가 0(진실을 아는 사람) 그룹인 경우
        parent[b] = a
    else:
        parent[a] = b


if len(temp) > 0:
    peopleTruth = temp[1:]
    numTruth = temp[0]

for num in peopleTruth:
    parent[num] = 0 #진실을 아는 사람은 0을 부모로 함

for i in range(M):
    party = list(map(int, readline().split()))[1:]
    for j in range(len(party)-1):
        union(party[j], party[j+1])
    peopleParties.append(party)

for party in peopleParties:
    know = False
    for person in party:
        if find(person) == 0:
            know = True
            break
    if not know:
        ans += 1

print(ans)
