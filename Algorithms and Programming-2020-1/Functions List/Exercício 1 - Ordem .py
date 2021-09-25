def ordem():
    vet.sort()
    print(f'O vetor em ordem é: {vet}')
vet = list(map(int, input("Vetor: ").split()))
ordem()