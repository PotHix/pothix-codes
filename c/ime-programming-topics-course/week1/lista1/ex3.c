/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc fatorial.c -o somad -Wall -O2 -ansi
 */

#include <stdio.h>

/**
 * FUNCAO RECEBE UM INTEIRO E DEVOLVE O FATORIAL (1*2*3*...*n) DO MESMO
 */
int fatorial(int n){
	int fatorial=1,i;
	for(i=2;i<=n&&n>1;i++){
		fatorial*=i;
	}
	return fatorial;
}

/*
INVARIANTE:
	"fatorial possui o fatorial de (i-1)" 

inicializacao:
	Na primeira iteração temos que i é inicializado com 2 e fatorial com 1, portanto temos "fatorial possui fatorial de (i-1)"
	
manutencao:
	Suponha que P(k) é verdadeiro. Vamos provar que P(k+1) tambem é verdadeiro.
	Na iteração em que P(k) vale temos que k=i, e "fatorial possui o fatorial de (i-1)", da execução da linha 3 temos que fatorial recebe a multiplicação dele mesmo por i, portanto "fatorial possui o fatorial de (i-1)". Agora a variável i é incrementada em 1, portanto vale para P(k+1).
	
termino:
	O laço da linha 2 termina quando i>n, e temos que "fatorial possui o fatorial de (i-1)"
*/

/**
 * Testa a função fatorial.
 */
int main () {
	printf ("Teste 1: ");
	printf ("%d = %d \n", 6, fatorial(3));

	printf ("Teste 2: ");
	printf ("%d = %d \n", 720, fatorial(6));

	printf ("teste 3: ");
	printf ("%d = %d \n", 3628800, fatorial(10));

	printf ("teste 4: ");
	printf ("%d = %d \n", 1, fatorial(1));

	return 0;
}
