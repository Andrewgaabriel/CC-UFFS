vet = list(map(int, input("Vetor: ").split())) #10 20 30 40 50
posR = int(input('Posição a ser removida: ')) #3
vet.pop(posR)
print("+" * 30)
print(f"Novo vetor: {vet}")
print(f"Novo tamanho do vetor: {len(vet)}")

