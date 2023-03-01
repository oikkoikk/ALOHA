import sys

readline = sys.stdin.readline

brackets = readline().rstrip()
stack = []
tmp = 1
res = 0

for i in range(len(brackets)):
    b = brackets[i]

    if b == '(':
        tmp *= 2
        stack.append(b)
    elif b == '[':
        tmp *= 3
        stack.append(b)

    elif b == ')':
        if not stack or stack[-1] == '[':
            res = 0
            break
        if brackets[i-1] == '(':
            res += tmp
        tmp //= 2
        stack.pop()
    elif b == ']':
        if not stack or stack[-1] == '(':
            res = 0
            break
        if brackets[i-1] == '[':
            res += tmp
        tmp //= 3
        stack.pop()

if stack:
    res = 0

print(res)
