	.data
	
matriz: .word 2, 8, -3, 7, 1, -2, 4, 5, 3, 5, 1, -4
	
	.text
main:
	la a0, matriz
	li a1, 3 # numero de linhas da matriz
	li a2, 4 # numero de colunas da matriz
	
	
	### INSERE AQUI O NUMERO PARA ENCONTRAR NA MATRIZ:
	li a3, 9 # numero a ser buscado na matriz
	
	
	jal t6, f_numero_na_matriz

	
	j end
	


f_numero_na_matriz:
	jal busca_endereco
	jal clean_tregs
	jal find_linha # em a6 tem a linha que esta o numero
	jal find_coluna # em a4 tem a coluna que esta o numero
	mv a0, a6
	mv a1, a4
	jal clean
	
	
	jr t6 # retorna para o main

clean:
	addi t0, zero, 0
	addi t1, zero, 0
	addi t2, zero, 0
	addi t3, zero, 0
	addi t4, zero, 0
	addi t5, zero, 0
	addi s0, zero, 0
	addi s1, zero, 0
	addi s2, zero, 0
	addi s3, zero, 0
	addi s4, zero, 0
	addi s5, zero, 0
	addi s6, zero, 0
	addi s7, zero, 0	
	addi s8, zero, 0
	addi s9, zero, 0
	addi s10, zero, 0
	addi s11, zero, 0
	addi a2, zero, 0
	addi a3, zero, 0
	addi a4, zero, 0
	addi a5, zero, 0
	addi a6, zero, 0
	addi a7, zero, 0
	ret
	
	
	
### FUNÇÃO QUE ENCONTRA A COLUNA DA INCIDENCIA
### RETORNA EM A4 O NUMERO DA COLUNA
find_coluna:
	#a5 tem o endereço inicial da linha
	#a6 contem a linha (inteiro)
	#a7 tem o endereço onde esta meu numero
	li t0, 0
	li t1, 4
	
	mul t2, t1, a2 # X = 4 * numero de colunas
	
	add s10, a5, t2 # endereço final da linha 
	add s1, a5, zero # endereço inicial da linha = X
	add t0, zero, zero # count
	
cond_parada_loop3:
	bge s1, s10, end_loop3
	beq a7, s1, achou_coluna
	j update_control3
	
update_control3:
	addi t0, t0, 1
	addi s1, s1, 4
	j cond_parada_loop3
	
	
achou_coluna:
	add a4, t0, zero # recebe o numero da coluna
	j end_loop3
	
end_loop3:
	ret
	
	
	
	
	
	
	
	
	
	





### FUNÇAO QUE ENCONTRA A LINHA EM QUE ESTA A OCORRENCIA DO NUMERO
### retorna em a5 o endereço inicial da linha
### retorna em a6 o numero da linha
### ----------------------------------------------------------------
find_linha:
	la a0, matriz
	#  a7 tem o endereço de onde esta o meu numero
	li t0, 0 # counter de colunas = Y
	li t1, 4 # bits

	mul t2, t1, a2 # X = 4 * numero de colunas
	add t3, t2, a0 # X = endereço inicial do vetor + X

cond_parada_loop2:
	bgt t0, a2, end_loop2
	blt a7, t3, achou_linha
	
update_control2:
	addi t0, t0, 1 # y++
	mul t2, t1, a2 # 4 * numero de colunas
	add t3, t2, t3 # X = endereço inicial do vetor + X
	j cond_parada_loop2
	
achou_linha:
	add a6, zero, t0 # contem a linha
	sub a5, t3, t2
	#add a5, zero, t3
	ret
	
end_loop2:
	ret
### ----------------------------------------------------------------
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
clean_tregs:
	addi t0, zero, 0
	addi t1, zero, 0
	addi t2, zero, 0
	addi t3, zero, 0
	addi t4, zero, 0
	ret
	

### --------------------------------------------------------------------------------
### FUNÇÃO QUE BUSCA O ENDEREÇO DO NUMERO QUE ESTA SENDO PROCURADO. *chamar com jal
## -> retorna em a7 o endereço de onde esta o numero procurado

busca_endereco:
	mul t1, a1, a2 #contém o tamanho da matriz
	add t2, zero, a0 #contem o endereço inicial da matriz
	addi t3, zero, 0 #counter para percorrer a matriz
	
cond_parada_laco1:
	bge t3, t1, end_loop
	
corpo_laco1:
	lw t4, 0(t2) # carrega o valor da memoria para verificar
	bne t4, a3, update_control # verifica se é diferente, se for branch, se não vai pra baixo 
	add s1, zero, t2 # carrega o endereço de onde o numero foi encontrado
	
update_control:
 	addi t2, t2, 4
    	addi t3, t3, 1
    	j cond_parada_laco1

end_loop:
	beqz s1, nao_achou
	mv a7, s1 # passa para a0 o endereço de onde esta o valor na matriz
	ret
### ----------------------------------------------------------------------------------
	
nao_achou:
	
	addi a0, zero, -1
	addi a1, zero, -1
	jal clean
	jr t6 #nao achou acabou tudo
	
	
end:
	nop