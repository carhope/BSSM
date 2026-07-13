arr= [
"phantom",
"mirage",
"quantum",
"oracle",
"nebula",
"vortex"
]

result=""

for i in range(len(arr)):
    result+=arr[i][i%4]

print(result)