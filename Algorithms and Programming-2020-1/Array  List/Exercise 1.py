veta = list(map(int, input("Vetor 1: ").split())) #5 6 8 7 8 5 10 4 3 2
vetb = list(map(int ,input('Vetor 2: ').split())) #1 6 18 17 8 5 100 4 3 2
var = int(input('Variável: '))
for c in range(0, len(veta)):
    if var==veta[c]:
        pos = c
print('##' *30)
print(f'A posição do número no vetor A é {pos}')
print(f'O elemento na posição {pos} no vetor B é {vetb[pos]}')