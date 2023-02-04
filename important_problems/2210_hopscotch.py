import sys

numField = []
ans = set()
dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]  # y x


def isInside(x, y):
    return 0 <= x and x < 5 and 0 <= y and y < 5


def DFS(x, y, num):
    num += numField[y][x]

    if len(num) == 6:
      ans.add(num)
      return
    for i in range(4):
      nextX = x + dir[i][1]
      nextY = y + dir[i][0]

      if isInside(nextX,nextY):
        DFS(nextX, nextY, num)

for _ in range(5):
    numField.append(sys.stdin.readline().split())

for y in range(5):
    for x in range(5):
        DFS(x, y, "")

print(len(ans))
