		.data

	msgA: .asciz "Digite o valor A: "
	msgB: .asciz "Digite o valor B: "
	msgC: .asciz "Digite o valor C: "
	ehtri: .asciz "Eh triangulo! "
	naoehtri: .asciz "Nao Eh triangulo! "
    	vector_len: .word 
    	
    	
    
		.text

main:
	#-----------------------------------------------------------
	# Imprime a mensagem A, lê o valor do teclado e coloca em S0

	la a0, msgA
	li a7, 4
	ecall
	
	li a7, 5
	ecall
	mv s0, a0 # s0 == A;
	
	#-----------------------------------------------------------
	# Imprime a mensagem B, lê o valor do teclado e coloca em S1
	
	la a0, msgB
	li a7, 4
	ecall
	
	li a7, 5
	ecall
	mv s1, a0 # s1 == B;
	
	#-----------------------------------------------------------
	# Imprime a mensagem C, lê o valor do teclado e coloca em S2
	
	la a0, msgC
	li a7, 4
	ecall
	
	li a7, 5
	ecall
	mv s2, a0 # s2 == C;
	
	#-----------------------------------------------------------
	# Passa os parâmetros para usar a função ehTriangulo
	
	mv a0, s0
	mv a1, s1
	mv a2, s2
	
	j ehTriangulo
	
	
ehTriangulo:
	mv s0, a0
	mv s1, a1
	mv s2, a2
	
	jal t6, verify #faz a organização dos valores e deixa em ordem 
	
	mv s0, a0 # maior valor (A)
	
	add t1, a1, a2 # (B + C)


	blt s0, t1, isTri
	addi a0, zero, 0
	
	la a0, naoehtri
	li a7, 4
	ecall
	
	jal end

	
isTri:
	addi a0, zero, 1
	
	la a0, ehtri
	li a7, 4
	ecall
	
	jal end
	
verify:
	bgt s0, s1, S0Maior
	j S1Maior
	
S1Maior:
	bgt s1, s2, S1Maior2
	mv a0,s2
	mv a1,s1
	mv a2,s0
	jr t6
	
S1Maior2:
	bgt s0, s2, S0MaiorQueS2
	mv a0,s1
	mv a1,s2
	mv a2,s0
	jr t6
	
S0MaiorQueS2:
	mv a0, s1
	mv a1,s0
	mv a2,s2
	jr t6
	
S0Maior:
	bgt s0, s2, S0Maior2
	mv a0, s2
	mv a1, s0
	mv a2, s1
	jr t6
	
S0Maior2:
	bgt s1, s2, S1MaiorQueS2
	mv a0,s0
	mv a1,s2
	mv a2,s1
	jr t6
	
S1MaiorQueS2:
	mv a0,s0
	mv a1,s1
	mv a2,s2
	jr t6

	
	
end: 
	nop

	