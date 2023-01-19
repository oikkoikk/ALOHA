import sys

N = int(input())


conferences = sorted([list(map(int, sys.stdin.readline().split()))
                      for _ in range(N)], key=lambda time: (time[1], time[0]))
# 시작과 동시에 끝나는 회의가 있을 수 있으므로, 끝나는 시간이 같다면 일찍 시작하는 순으로 정렬

cnt = 1 # 첫 번째 회의는 무조건 포함
lastConf = conferences[0]

for i in range (1,N):
    if conferences[i][0] >= lastConf[1]:
        cnt += 1
        lastConf = conferences[i]

print(cnt)
