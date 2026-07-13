def isFull(s):
    if top >= len(s)-1:
        return True
    return False

def push(d,s):
    global top
    if isFull(s):
        print('Stack is Full.')
        return
    top += 1
    s[top] = d
    return s[top]

def isEmpty(s):
    if top == -1:
        return True
    else:
        return False


def pop(s):
    global top
    if isEmpty(s):
        print("공백이다")
    return
    data = s[top]
    s[top] = None
    top -= 1
    return data

p = 1
size = 0
while p == 1:
    inp = int(input('삽입 1, 삭제 2,종료 3'))
    if inp == 3:
        p = 2
        break
    elif inp == 1:
        size = int(input('사이즈'))
        a = input('들어갈 것')
        push(a,s)
    
    s = [None for i in range(size)]
    global top
    top = -1
    