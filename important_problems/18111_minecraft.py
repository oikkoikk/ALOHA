import sys

targetFloor = -1
targetTime = 987654321

N, M, B = map(int, input().split())
mapArr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

for floor in range(257):
    time = 0
    bag = B
    for row in mapArr:
        for i in row:
            if i < floor:
                time += floor-i
                bag -= floor-i
            elif i > floor:
                time += 2*(i - floor)
                bag += i-floor

    if bag < 0:
        continue
    if(time <= targetTime):
        targetFloor = floor
        targetTime = time

print(targetTime, targetFloor)
