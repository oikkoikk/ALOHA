import sys
import heapq

readline = sys.stdin.readline

N = int(readline().rstrip())
M = int(readline().rstrip())

students = {}
recommendations = list(map(int, readline().split()))

for student in recommendations:
    if student not in students:
        if len(students) >= N:
            del_student = heapq.nsmallest(1, students, lambda x : students[x])[0]
            students.pop(del_student)

        students[student] = 1
    else:
        students[student] += 1

print(*sorted(students.keys()))
