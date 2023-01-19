name = "BBBBAAAABA"


def updown(char):
    # A에서 위로 가는 경우
    cnt1 = abs(ord('A')-ord(char))
    # A에서 아래로 가는 경우
    cnt2 = abs(ord('Z')-ord(char)) + 1

    return min(cnt1, cnt2)

def leftright(str):
    cnt = len(str) - 1;

    for i in range(len(str)):
        Aidx = i +1
        while (Aidx < len(str) and name[Aidx] == 'A'):
            Aidx+=1

        cnt = min(min(cnt, (i * 2) + len(str) - Aidx), i + 2*(len(str)-Aidx))
        #그냥 직진 / 갔다가 중간에 뒤로 / 뒤로 갔다가 직진  -> 비교!!
    return cnt


def solution(name):
    updownResult = 0
    for char in name:
        updownResult += updown(char)

    return updownResult + leftright(name)


print(solution(name))
