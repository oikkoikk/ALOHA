import sys

readline = sys.stdin.readline

N = int(readline().rstrip())

str = readline().rstrip()
last = str[-1]  # 마지막 문자
first = str[0]  # 첫 문자

red = ' '.join(str.split('B')).split()
blue = ' '.join(str.split('R')).split()

r_red, l_red, r_blue, l_blue = red[0:], red[0:], blue[0:], blue[0:]

if first == 'R':
    l_red = red[1:]
elif first == 'B':
    l_blue = blue[1:]

if last == 'R':
    r_red = red[:-1]
elif last == 'B':
    r_blue = blue[:-1]

r_red = ''.join(r_red)
l_red = ''.join(l_red)
r_blue = ''.join(r_blue)
l_blue = ''.join(l_blue)

print(min(len(r_red), len(r_blue), len(l_red), len(l_blue)))
