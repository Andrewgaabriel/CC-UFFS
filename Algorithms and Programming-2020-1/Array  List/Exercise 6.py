vet = list(map(int, input("Vetor: ").split()))
par = []
imp = []
for c in range(0, len(vet)):
    if vet[c]%2==0:
        par.append(vet[c])
    else:
        imp.append(vet[c])
print("=" * 35)
print(f'Há {len(par)} números pares, sendo eles: {par}')
print(f'Há {len(imp)} números impares, sendo eles: {imp}')
