L, R = input().split()
cnt = 0


def find(start, end):
    global cnt
    if len(start) == len(end):
        # 자릿수가 같을 때
        idx = start.find('8')
        if idx == -1:
            return
        else:
            if end[idx] == '8':
                if idx != len(end)-1 and start[:idx] == end[:idx]:
                    cnt += 1
                    find(start[idx+1:], end[idx+1:])
                else:
                    if start == end:
                        cnt += 1
                    else:
                        return

    else:
        # 자릿수가 다를 때
        return


find(L, R)

print(cnt)
