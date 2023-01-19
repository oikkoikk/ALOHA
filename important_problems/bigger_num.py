def solution(number, k):
    stack = []
    for num in number:
        while stack and stack[-1] < num and k > 0:
            k -= 1
            stack.pop()
        stack.append(num)
    return ''.join(stack[:len(stack)-k]) #"654321"같은 수는 k에 상관없이 pop이 일어나지 않는다...!
