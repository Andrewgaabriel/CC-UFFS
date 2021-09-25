vet = list(map(int, input("Vetor: ").split())) #5 6 8 7 8 5 10 4 3 2
mai = men = 0
for c in range(len(vet)):
    if vet[c] > mai:
        mai = vet[c]
    elif vet[c] < mai:
        men = vet[c]
print(f'Valor máximo: {mai}')
print(f'Valor mínimo: {men}')