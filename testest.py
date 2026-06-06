arr = ['A','B','C']
for i in range(len(arr)):
    rest = arr[:i] + arr[i + 1:]
    print(rest)