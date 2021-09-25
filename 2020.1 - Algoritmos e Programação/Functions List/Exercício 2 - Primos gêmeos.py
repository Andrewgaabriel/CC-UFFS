def primo(n):
    limite=(n//2)+1
    for c in range(2, limite):
        if n % c == 0:
            return False
    return True


p1 = 2
for i in range(3,1000+1,1):
    if primo(i)==True:
        if i-p1<=2:
            print(p1,i)
        p1=i