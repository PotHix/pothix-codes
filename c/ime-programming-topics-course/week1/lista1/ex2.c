/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc soma_digitos.c -o somad -Wall -O2 -ansi
 */

#include <stdio.h>

/**
 * FUNÇÃO QUE RECEBE UM INTEIRO E DEVOLVE A SOMA DOS DIGITOS DESSE INTEIRO
 */
int soma_digitos(int n) {
	int soma=0, i;
	for(i=0; n>0; i++,n/=10) {
		soma+=(n%10);
	}
	return soma;
} 

/*
INVARIANTE:
	"Soma possui a soma de i digitos do numero"

inicializacao:
	A variável soma é iniciada com 0, portanto temos que "Soma possui a soma de i digitos do numero"
	
manutencao:
	Suponha que P(k) é verdadeiro. Vamos provar que P(k+1) tambem é verdadeiro.
	Na iteração em que P(k) vale temos que k=i, e "Soma possui a soma de i digitos do numero", da execução da linha 3 temos que soma recebe o resto da divisão por 10, assim recebendo o valor do ultimo digito. Agora a variável n é dividida por 10 e a variável i é incrementada em 1, portanto vale P(k+1) e a invariante se mantém.

termino:
	O laço da linha 2 termina quando n<0, portanto temos que "Soma possui a soma de i digitos do numero"
*/

/**
 * Testa a função soma_digitos.
 */
int main () {
	printf ("Teste 1: ");
	printf ("%d = %d \n", 1, soma_digitos (10));

	printf ("Teste 2: ");
	printf ("%d = %d \n", 0, soma_digitos (00000));

	printf ("Teste 3: ");
	printf ("%d = %d \n", 43, soma_digitos (999912310));

	return 0;
}
