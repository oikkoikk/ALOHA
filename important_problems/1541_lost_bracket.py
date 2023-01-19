string = input().split('-')  # -를 기준으로 식 분할
# ex. 60-30+29-90-10+80 -> ['60', '30+29', '90', '10+80']
# 따라서 맨 처음 원소만 더해주고, 나머지는 계속 빼주면 된다

num = []
result = 0

for token in string:
    tempSum = 0
    if token.find('+'):
        pl = token.split('+')  # + 연산 직접!
        for temp in pl:
            tempSum += int(temp)
    else:
        tempSum = int(token)
    num.append(tempSum)

result += num[0]

for i in range(1, len(num)):
    result -= num[i]

print(result)
