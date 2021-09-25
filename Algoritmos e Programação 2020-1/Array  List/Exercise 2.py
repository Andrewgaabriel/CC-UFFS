princ = list(map(int, input("Vetor: ").split()))
A = princ[:5]
B = princ[5:10]
princ.clear()
n = 5
soma = [0] * n
for i in range(n):
    soma[i] = A[i] + B[i]
print('#'*30)
print(f'SOMA = {soma}')