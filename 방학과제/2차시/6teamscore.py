n = int(input())
total = {}
for i in range(n):
	team,score = map(str,input().split())
	score = int(score)
	if team in total:
		total[team] += score
	else:
		total[team] = score

for i in total:
	print(i,total.get(i))
	