n = int(input())
all_students = []

for _ in range(n):
    name, score = input().split()

    all_students.append([-int(score), name])


for score, name in sorted(all_students):
    print(name)