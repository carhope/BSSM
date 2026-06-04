s = []
top = -1
while True:
    top += 1
    e = input()
    print(top)
    if top >= 5:
        break
    if top >= 0 :
        s.append(e)
print(s)