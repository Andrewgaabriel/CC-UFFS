dup = []
ent = input("Vetor: ").split() #5 4 3 2 2 3 4 5
for i in range(0, len(ent)): #0 1 2 3 4 5 6 7
    item = int(ent[i])
    cont = 0
    for j in ent:
        if int(j) == item:
            cont += 1
            if cont >= 2 and item not in dup:
                dup.append(item)
print('+' * 35)
print(f'O número de elementos duplicados é: {len(dup)}')
print('Sendo o(s) número(s):', end=" ")
for n in dup:
    print(n, end=" ")