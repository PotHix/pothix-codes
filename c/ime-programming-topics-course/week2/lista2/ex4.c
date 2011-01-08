/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc exercicio4.c -o exercicio4 -Wall -O2 -ansi
 */

#include <stdio.h>

/**
 * FUNÇÃO RECEBE DOIS INTEIROS, SENDO O PRIMEIRO A BASE E O SEGUNDO O
 * EXPOENTE, E RETORNA O RESULTADO DA OPERACAO DE K^N
 */

int pot (int k, int n){
	if(n<1){return 1;}

	return k * pot(k,n-1);
}

/**
 * Testa a função pot.
 */
int main () {
	printf ("Teste 1: ");
	printf ("%d = %d \n", 4, pot(2,2));
   
	printf ("Teste 2: ");
	printf ("%d = %d \n", 125, pot(5,3));
   
	printf ("Teste 3: ");
	printf ("%d = %d \n", 32, pot(2,5));

	return 0;
}
