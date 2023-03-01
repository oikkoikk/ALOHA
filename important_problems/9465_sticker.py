import sys

readline = sys.stdin.readline

T = int(readline().rstrip())
for _ in range(T):
  N = int(readline().rstrip())
  stickers = []
  for i in range(2):
    stickers.append(list(map(int,readline().split())))
  
  for i in range(1,N):
    if i == 1:
      stickers[0][1] += stickers[1][0]
      stickers[1][1] += stickers[0][0]
    else:
      stickers[0][i] += max(stickers[1][i-1], stickers[1][i-2])
      stickers[1][i] += max(stickers[0][i-1], stickers[0][i-2])

  print(max(stickers[0][N-1],stickers[1][N-1]))

