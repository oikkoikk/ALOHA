import sys

test = 1

while True:
    inputStr = "".join(sys.stdin.readline().split())

    if inputStr[0] == "-":
        exit()

    stack = 0  # {
    cnt = 0

    for char in inputStr:
        if char == '{':
            stack += 1
        elif char == '}':
            if stack:
                stack -= 1
            else:
                cnt += 1
                stack += 1

    while stack:
        if stack % 2 == 0:
            cnt += 1
        stack -= 1

    print(str(test) + ". " + str(cnt))
    test += 1
