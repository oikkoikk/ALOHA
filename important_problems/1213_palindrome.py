str = input()
str_list = sorted([char for char in str])
key_set = set(str_list)
str_dict = dict()

odd_alpha = "" #홀수개인 알파벳을 가운데에 넣기 위해
half = "" #대칭이니까 왼쪽짜리만..

for alpha in key_set:
    cnt = str_list.count(alpha)
    if(cnt % 2 != 0):
        if(odd_alpha != ""): #홀수개인 알파벳이 2개 이상이면 팰린드롬 불가!
            print("I'm Sorry Hansoo")
            exit()
        else:
            odd_alpha = alpha
            str_list.remove(odd_alpha)
            cnt -= 1
    str_dict[alpha] = cnt

str_dict = dict(sorted(str_dict.items()))

for alpha, cnt in str_dict.items():
    for i in range(int(cnt/2)):
        half += alpha

print(half+odd_alpha+half[::-1])
