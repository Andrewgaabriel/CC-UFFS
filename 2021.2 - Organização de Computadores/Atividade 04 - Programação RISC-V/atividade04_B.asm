#ordenação de um vetor de inteiros

	.data
	
vetor: .word 8 ,6 ,2 ,3 ,9
vetor_len: .word 5
sep: .asciz " ,"
div: .asciz "\n Ordenado: \n"
	
	.text
	
	
	
main:
	la a0, vetor	#endereço inicial do vetor
	lw a1, vetor_len 	#tamanho do vetor = N
	
	
	
	jal f_imprime
	jal ordena_1
	
	la a0, div
	li a7, 4
	ecall
	
	jal f_imprime
	j encerra
	
	
	
ordena_1:
	la a0, vetor	#endereço inicial do vetor
	add t0, zero, a0 #armazena o endereco inicial do vetor em t0
	add t1, zero,a1 # armazena o tamanho do vetor	
	addi s0, zero, 1 # -> K
	addi s1, zero, 0 # -> J
	addi s2, t1, -1  # -> N-1
	
for_ordena1:
	blt s0, t1, for_ordena2 # K < N
	ret
	
for_ordena2:
	blt s1, s2, corpo_for_B # J < N-1
	j atualiza_K
	
atualiza_K:
	addi, s0, s0, 1
	j for_ordena1
	
corpo_for_B:
	addi s3, s1, 1 # -> J+1
	
	slli s4, s1, 2 #multiplica por 4 para depois resgatar o valor na memoria (J)
	add s5, s4, a0 #soma s4 com o endereço inicial
	lw s6, 0(s5) # passa para s6 o valor buscado no vetor
	
	slli s7, s3, 2 #multiplica por 4 para depois resgatar o valor na memoria (J+1)
	add s8, s7, a0 #soma s7 com o endereço inicial
	lw s9, 0(s8) # passa para s9 o valor buscado no vetor
	
	bgt s6,s9, faz_swap
	j atualiza_J

atualiza_J:
	addi s1, s1, 1
	j for_ordena2
	
faz_swap:
	sw s9, 0(s5) # pega o valor da posição A e coloca na B
    	sw s6, 0(s8) # pega o valor da posição B e coloca na A
	j atualiza_J
	
	


##### > Função que imprime o vetor < ######

f_imprime:
	#IMPRIME O VALOR DA PRIMEIRA POSIÇÃO
	la a0, vetor	#endereço inicial do vetor
	lw a1, vetor_len 	#tamanho do vetor = N
	mv t0, a0 #t0 tem o endereço do vetor
	addi t1, zero, 0 # t1 = i
	mv t2, a1 # tamanho do vetor
	
cond_parada_f_imprime:
	bge t1, t2, end_loop
	
corpo_loop:
	
	lw s1, 0(t0) #carrega em s1 o valor presente no endereço t0
	mv a0, s1 #carrega o valor em a0 para ser impresso
	
	li a7, 1
	ecall
	
	la a0, sep
	li a7, 4
	ecall
	
update_control:
 	addi t0, t0, 4
    	addi t1, t1, 1
    	j cond_parada_f_imprime
 
end_loop:
	ret
	
encerra:
	nop 