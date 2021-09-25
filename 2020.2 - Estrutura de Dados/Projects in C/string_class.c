#include <stdio.h>
#include <string.h> //precisa importar para as funções de string.
#include <ctype.h> //utilizamos para o toupper ou tolower.

int main(){
	//Em C não temos o tipo de String, assim, criamos um vetor de char para armazenar textos ou palavras
	char string[100] = "Professor"; //Apenas podemos fazer esse tipo de atribuição na declaração de uma string.
	char string2[400];
	char *string3 = "Aluno"; //Podemos declarar dessa forma, porém a string terá tamanho 5;
	char *string4; //Podemos declarar assim também, porém, neste formato você terá que alocar memória para essa string (veremos isso nas próximas aulas)

	/**
	 * Ao declarar uma string, geralmente, colocamos um tamanho grande para o vetor. Apesar de parecer
	 *    um desperdício de memória, não podemos, de maneira simples, expandir o tamanho da string em
	 * 	  tempo de execução.
	 */


	//Para imprimir uma string utilizamos o "%s"
	printf("Bem vindo %s\n", string);

	//para ler uma string com scanf basta utilizar o "%s"
	printf("Digite uma palavra: ");
	scanf("%s", string2);	//lembre-se que dessa forma vc apenas lê uma palavra, pois o scanf pega os caracteres até encontrar um 'espaço' ou \n
	getc(stdin); //Isso serve para resolver o problema do \n na leitura de uma string, ou de um inteiro, pois o scanf só le até ele, e o deixa na entrada. Se vc comentar essa linha verá que o fgets não lerá nada.
	//para ler uma linha inteira
//	gets(string); //porém essa forma de leitura é insegura pois permite ler strings maiores que o tamanho da variável, o que causa um erro.

	printf("Digite Várias palavras: ");
	//uma forma mais segura de ler uma string é utilizando o fgets. Ele vai validar o tamanho máximo que a string pode suportar, baseado no parâmetro, evitando o erro
	fgets(string2, sizeof(string2), stdin); //preferencialmente, quando ler mais de uma palavra usar esse cara.
	/**
	 * Os parâmetros do fgets são os seguintes:
	 * 	1 - variável onde a string vai ser armazenada
	 *  2 - tamanho da variável, por isso usamos sizeof
	 *  3 - de onde será lido, no caso usamos "stdin" para ler do teclado.
	 */
	//Um inconveniente de utilizar o fgets é que ele lê o \n e o salva na variável
		//Para eliminar ele utilizamos o seguinte comando:
	string2[strcspn(string2, "\n")] = '\0'; //strcspn retorna a posição na string2 onde o "\n" aparece. -> nesse caso "\n" é com aspa dupla, pois a função pede duas strings não um char (onde usaríamos '\n').



	/* IMPORTANTE!
		Outra operação muito importante é a atribuição de strings.
	     string2 = "Não pode fazer isso";
	     string = string2; //nem isso
		C não permite fazer atribuições literais de strings, lembre que são vetores, então não podemos fazer isso diretamente.
		Pelo fato de strings serem vetores teríamos que atribuir posição por posição... Mas C é divertido, então, tem uma função que nos ajuda quanto a isso.
	*/
	//Uma das funções que pode ser utilizada é o strcpy
	strcpy(string2, "Valor para atribuir"); //se eu quiser atribuir uma valor para outro
	strcpy(string2, string); //se eu quiser copiar o valor de uma string para outra
	//O problema, é que como o gets, essa função nao faz validação do tamanho de string, assim pode ocorrer o erro de copiar uma string maior do que o vetor suportaria.

	//Para eliminar o problema, utilizamos a função snprintf que corrige o problema da string e é mais flexível
	snprintf(string2, sizeof(string2), "%s", "Valor para atribuir");//para um valor fixo
	snprintf(string2, sizeof(string2), "%s", string); //para copiar o valor de uma string.
	/**
	 * Os parâmetros da função são:
	 * 	1 - Variável onde vai ser colocada a string
	 *  2 - Tamanho da variável
	 * 	3 - formato-> mesma ideia de formato do printf
	 *  4 - variáveis utilizadas para o formato, valores que vão ser atribuídos.
	 */


	/*
	 *	IMPORTANTE!
	 *	Já sabemos ler a string e atribuir uma string a outra, então precisamos entender como funciona a comparação de strings.

		Não podemos compara string diretamente
			if (string == string2)
		Como são vetores, a comparação deve ser feita posição para posição. Mas não ache que o C te deixaria na mão, C é seu amigo S2.
		Para fazer as comparações utilizamos a função strcmp
	*/
	int resultadoComparacao = strcmp(string, string2); //podemos utilizar diretamente no IF, mas vou usar assim para explicar melhor a função.
	if (resultadoComparacao == 0){
		printf("As strings são iguais!\n");
	} else if (resultadoComparacao < 0){
		printf("A variavel string vem antes da string2 na ordem alfabética!\n");
	} else if (resultadoComparacao > 0){
		printf("A variavel string2 vem antes da string na ordem alfabética!\n");
	}
	/* Em resumo:
		strcmp(string2, string) retorna um valor inteiro X
		x == 0, se ambas forem iguais
		x < 0, se primeira vem antes da segunda
		x > 0, segunda antes da primeira
	*/

	/**
	 * Para saber o tamanho de um string temos que contar todas as posições do vetor até achar um '\0' (delimita o fim da string).
	 * 		Para facilitar nosso trabalho o C disponibiliza a função strlen() que retorna o tamanho da string.
	 * 	Lembre que o tamanho de string é diferente do sizeof da string. O sizeof é utilizado para ver o número de bytes reservados para uma variável em memória, enquanto o strlen vai contar as posições da string até achar o \0;
	 */
	printf("O tamanho da string2 é %ld, já o sizeof é %ld\n", strlen(string2), sizeof(string2));

	/**
	 * Durante a aula conversamos e tentamos utilizar uma função para deixar a string maíuscula.
	 * 	Tentamos utilizar a função strup, porém essa função não esta mais disponível, no caso em alguns sistemas ela pode funcionar e em outros não :(
	 * Infelizmente não temos mais uma função padronizada para desempenhar esse papel, então temos que fazer um loop e converter char por char.
	 * Utilizamos TOUPPER para maiúscula e TOLOWER para minusculas.
	 */
	int j=0;
	while(j<strlen(string2)){
		string2[j] = toupper(string2[j]); //para tornar maiúsculo
		//string2[j] = tolowe(string2[j]); //para tornar minusculo
		j++;
	}

	printf("String maiúscula: %s\n", string2);

	return 0;
}
