import random

# CLASSES


class customer:
    Fname = ''
    Lname = ''
    cpf = ''
    passw = ''
    CardN = 0
    limit = 0.0
    Dlimit = 0.0
    sol = 0
    trav = 0.0
    phar = 0.0
    mktplc = 0.0
    foods = 0.0
    car = 0.0
    others = 0.0


# FUNÇÕES:


def verifycpf(cpfv):  #Validação do CPF
    s = 0
    for i in range(9):
        n = int(cpfv[i])
        s += n * (10 - i)
    resto = s % 11
    a = 0
    if resto < 2:
        a = 0
    elif resto >= 2:
        a = 11 - resto
    t = 0
    for i in range(10):
        n = int(cpfv[i])
        t += n * (11 - i)
    b = 0
    resto2 = t % 11
    if resto2 < 2:
        b = 0
    elif resto2 >= 2:
        b = 11 - resto2

    if cpfv[9] != a or cpfv[10] != b:
        return False
    else:
        return True


def menu():  # FUNÇÃO INICIAL/MENU
    print("=" * 20, '+', "=" * 20)
    print('=== WELCOME TO THE CC BANK SYSTEM V1.0 ===')
    print("=" * 20, '+', "=" * 20)
    print("")
    print("=" * 40)
    print('MENU:')
    print("=" * 40)
    print('1. Costumer access.')
    print('2. Root access.')
    print('3. Exit.')
    print("=" * 40)
    return int(input('CHOOSE ONE OPTION(1/2/3):  '))


def RootLogin():  # LOGIN ROOT
    print("=" * 40)
    ruser = input('User: ')
    rpass = input('Password: ')
    print("=" * 40)
    if ruser == "admincc" and rpass == 'admincc':
        RootFunc()
    else:
        print('Incorrect username and password!')


def RootFunc(): #Funções do ROOT
    OpRootMenu = 0
    while OpRootMenu != 4:
        print("=" * 40)
        print('WELCOME ROOT!')
        print("MENU:")
        print("=" * 40)
        print('1. REGISTER NEW COSTUMER')
        print('2. CHECK COSTUMERS')
        print('3. FREE UP MORE CREDIT')
        print('4. EXIT')
        print("=" * 40)
        OpRootMenu = int(input('Choose one option(1/2/3): '))
        if OpRootMenu == 1:
            RootFunc1()  # cadastro de novos clientes
        elif OpRootMenu == 2:
            RootFunc2(dadoscliente)  # listagem de clientes
        elif OpRootMenu == 3:
            RootFunc3(dadoscliente)  # liberar crédito


def ClientFunc(client): #Funções do Cliente
    OP = 0
    while OP != 5:
        print(f"What do you want to do today {client.Fname}?")
        print("=" * 40)
        print('1. PURCHASE RECORD')
        print('2. EXPENSES CHECK (by categories)')
        print('3. PAYMENT')
        print('4. LIMIT CHECK')
        print('5. EXIT')
        print("=" * 40)
        OP = int(input("CHOOSE ONE OPTION(1/2/3/4/5): "))
        if OP == 1: #FAZER COMPRAS
            print("=" * 40)
            print('==PURCHASE RECORD==')
            print("=" * 40)
            print('CATEGORIES:')
            print("1. Travel")
            print("2. Pharmacy")
            print("3. Marketplace")
            print("4. Foods")
            print("5. Car (fuel, maintenance) ")
            print("6. Others")
            print("=" * 40)
            cat = int(input('Choose a Category(1/2/3/4/5/6): '))
            value = float(input('Price: R$'))
            check = client.limit - value
            s = ''  # guardar o nome da categoria escolhida
            passtemp = str(input('Password: '))
            if passtemp != client.passw:
                print('Incorrect password! Try again.')

            else:
                if check < 0:
                    print(f'limit already exceeded!')
                    print(f'you have R$ {client.limit} available from your limit!')
                else:
                    client.limit = client.limit - value
                    if cat == 1:
                        s = 'Travel'
                        client.trav += value
                    elif cat == 2:
                        s = 'Pharmacy'
                        client.phar += value
                    elif cat == 3:
                        s = 'Marketplace'
                        client.mktplc += value
                    elif cat == 4:
                        s = 'Foods'
                        client.foods += value
                    elif cat == 5:
                        s = 'Car'
                        client.car += value
                    elif cat == 6:
                        s = 'Others'
                        client.others += value
                    print(f'You just registered R$ {value} expenses in {s}')
        elif OP == 2: #CHECAGEM DE GASTOS POR CATEGORIA
            print("=" * 40)
            print("==EXPENSES CHECK==")
            print("=" * 40)
            print(f'You spent R$ {client.trav} on Travel.')
            print(f'You spent R$ {client.phar} on Pharmacy.')
            print(f'You spent R$ {client.mktplc} on Marketplace.')
            print(f'You spent R$ {client.foods} on Foods.')
            print(f'You spent R$ {client.car} on Car.')
            print(f'You spent R$ {client.others} on Others.')
            print("=" * 40)
        elif OP == 3: #PAGAMENTO DE FATURA
            bill = client.trav + client.phar + client.mktplc + client.foods + client.car + client.others
            print("=" * 40)
            print("== PAYMENT ==")
            print("=" * 40)
            print(f'Your invoice amount is R$ {bill}')
            print('Would you like to pay the full invoice?')
            pay = float(input('Enter the total amount: R$ '))
            print("=" * 40)
            bill = bill - pay
            # cash = client.limit - bill
            if bill == 0:
                client.limit = client.limit + pay
                print(f'You have paid the entire invoice, your credit limit is {client.limit}')
                client.trav = 0.0
                client.phar = 0.0
                client.mktplc = 0.0
                client.foods = 0.0
                client.car = 0.0
                client.others = 0.0
            else:
                print(f"You entered the wrong value, try again!")
        elif OP == 4: #CHECAGEM DE LIMITE DE CRÉDITO E SOLICITAÇÃO DE AUMENTO
            print("=" * 40)
            print('== CREDIT LIMIT CHECK ==')
            print("=" * 40)
            print(f"Your current limit is R$ {client.limit}")
            print('Before requesting more credit limit, pay your invoice!')
            print("=" * 40)
            print('1. Request more credit limit')
            print('2. Exit')
            print("=" * 40)
            op3 = int(input('Choose one option(1/2):'))
            if op3 == 1:
                print("=" * 40)
                want = float(input('How much credit limit do you want?'))
                print("=" * 40)
                client.Dlimit = want
                client.sol = 1
                print("Your request will be analyzed!")
                print("=" * 40)

        elif OP == 5:
            break


def insertcost(client): #Cadastro de novos clientes
    client.Fname = input('First name: ')
    client.Lname = input('Last name: ')
    temp = list(map(int, input('CPF: ')))
    while verifycpf(temp) != True:
        print('Invalid CPF, try again!')
        temp = list(map(int, input('CPF: ')))
    else:
        print('Valid CPF!')
        client.cpf = temp
    senha = str(input('Create a 6-digit password: '))
    if len(senha) == 6:
        client.passw = senha
    else:
        while len(senha) != 6:
            print('Invalid 6-digit password! Try again')
            senha = str(input('Create a 6-digit password: '))
            if len(senha) == 6:
                client.passw = senha
    ganhos = float(input('Monthly earnings: '))
    client.limit = (ganhos * 0.75)
    client.CardN = random.randint(1000000000000000, 9999999999999999)


def RootFunc1(): #Cadastro de novos clientes
    print("=" * 40)
    print('REGISTRATION OF NEW CUSTOMERS')
    print("=" * 40)
    d1 = customer()
    insertcost(d1)
    dadoscliente.append(d1)
    print('===COMPLETE REGISTRATION===')
    print('CHECK YOUR ACCOUNT DATA:')
    print(f'First Name: {d1.Fname}')
    print(f'Last Name: {d1.Lname}')
    print(f'CPF: {d1.cpf}')
    print(f'6-digit password: {d1.passw}')
    print(f'Card number: {d1.CardN}')
    print(f'Credit limit: {d1.limit}')


def RootFunc2(client): #Listagem de clientes cadastrados
    for c in range(len(client)):
        print("=" * 40)
        print(f'First name: {client[c].Fname}')
        print(f'Last name: {client[c].Lname}')
        print(f'CPF: {client[c].cpf}')
        print(f'Password: {client[c].passw}')
        print(f'Card number: {client[c].CardN}')
        print(f'Credit Limit: {client[c].limit}')
        print("=" * 40)


def RootFunc3(clients):  #Liberar mais crédito
    print("=" * 40)
    print("Fetching requests...")
    print("=" * 40)
    for c in range(len(clients)):
        if clients[c].sol == 1:
            print("=" * 40)
            print(f'You have a request from {clients[c].Fname}')
            print(f'The desired credit limit is: R$ {clients[c].Dlimit}')
            print("=" * 40)
            print("Do you want to update the limit?")
            print("1. Yes")
            print("2. No")
            print("=" * 40)
            op4 = int(input('Option: '))
            print("=" * 40)
            if op4 == 1:
                clients[c].limit = clients[c].Dlimit
                clients[c].sol = 0
                print("Credit limit updated!")
            elif op4 == 2:
                clients[c].limit = clients[c].limit
                clients[c].Dlimit = 0.0
                clients[c].sol = 0
                print("Credit limit maintained!")


def CostAcess(client): #Login/Acesso do cliente
    print("=" * 40)
    print('WELCOME COSTUMER')
    print("=" * 40)
    print("PLEASE ENTER YOUR DATA")
    CostLogin = int(input('Card number: '))
    CostPass = str(input('Password: '))
    for c in range(len(client)):
        if client[c].CardN == CostLogin and client[c].passw == CostPass:
            print("=" * 40)
            print(f'Welcome {client[c].Fname} {client[c].Lname}')
            print("=" * 40)
            return c
    print("=" * 40)
    print('User not detected, try again! ')
    print("=" * 40)


# PROGRAMA

dadoscliente = []
op = 1
while op != 3:
    op = menu()
    if op == 1: #ACESSO DO CLIENTE
        a = CostAcess(dadoscliente) #{a} armazena a posição do cliente
        if a != "None":
            ClientFunc(dadoscliente[a])
    elif op == 2: #ACESSO DO ADMINISTRADOR/ROOT
        RootLogin()

print("===THANK YOU FOR USING OUR SYSTEM===")