def remoV():
    for c in range(len(A)):
        if A[c] == ",":
            A.pop(c)
            A.insert(c,".")


print('-'*30)
A = list(map(str, input('Número: ')))
print('-'*30)
remoV()
for i in range(len(A)):
    print(A[i], end="")
