#  **ATIVIDADE 3**




### **( A )** Crie a tabela teste (id integer primary key, value char(500))
 


```
> create table teste (id integer primary key, value char(500));
```


---

### **( B )** Adicione 10 linhas
 
```
> insert into teste values  (10, 'dez'),
                            (1, 'um'),
                            (2, 'dois'),
                            (3, 'tres'),
                            (4, 'quatro'),
                            (5, 'cinco'),
                            (6, 'seis'),
                            (7, 'sete'),
                            (8, 'oito'),
                            (9, 'nove');
```

---
### **( C )** Verifique o tamanho da tabela
 
```
> SELECT pg_size_pretty( pg_total_relation_size('teste'));
```
---

### **( D )** Insira uma tupla com id =10  em uma transação A (sem comitar)
 
```
(rodar no terminal 1 - TRANSAÇÃO A)

> begin;
> insert into teste values (10, 'dez');
```

---
### **( E )** Insira uma tupla com id =10  em uma transação B (sem comitar)
 
```
(rodar no terminal 2 - TRANSAÇÃO B)

> begin;
> insert into teste values (10, 'dez');
```
---


### **( F )** Explique o que aconteceu já que os dados são operados em cópias diferentes?
 
```
    Feito o comando de inserção no terminal A, ao tentar fazer no B ele não permite que a transação seja efetuada até que seja commitada a transação que está em execução no terminal A. E ao commitar a transação do terminal A é liberada a transação no terminal B, que aliás resulta em um erro pois o valor da inserção no terminal B é igual ao do terminal A (o valor a ser inserido tratava-se de uma chave primária impossibilitando valores iguais).
```

---








