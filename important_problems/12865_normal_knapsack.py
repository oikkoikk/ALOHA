import sys

input = sys.stdin.readline
N, K = map(int, input().split())
weight, value = [0], [0]
DP = [[0]*(K+1) for _ in range(N+1)]
# DP[A][B] = A번 물건까지 확인한 상태에서, 배낭 무게가 B일 때의 물건들의 가치의 최댓값

for i in range(N):
    temp_w, temp_v = map(int, input().split())
    weight.append(temp_w)
    value.append(temp_v)

for i in range(1, N+1):
    for j in range(1, K+1):
        w, v = weight[i], value[i]
        if j < w:
          #현재 배낭의 무게가 지금 확인하는 물건보다 가벼울 경우 (넣을 수 없음)
          DP[i][j] = DP[i-1][j]
        else:
            DP[i][j] = max(DP[i-1][j-w] + v, DP[i-1][j])
            #현재 보석을 넣어서 무게가 j가 된 경우 vs 안 넣고 무게가 j인 경우

print(DP[N][K])