def chahima(mage:str)->str:
    return 'chahuma\'s' + mage

def intro(name:str, age:int, *hobby):
    print(f'저는 {name}입니다')
    print(f'나이는 {age}살입니다')
    print('저의 취미는')
    for i in hobby:
        print(f'{i},')
    print('등이 있습니다')
yar = chahima('야루떵개')
print(chahima('야르'))
print(yar)
intro('차희망',16,'잠자기','책읽기','멍때리기','글쓰기')

