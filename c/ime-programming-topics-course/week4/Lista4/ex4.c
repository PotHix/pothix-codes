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
int potencia (int k, int n){
	if(n==1) return k;

	if(n%2==0) 
		return potencia(k,n/2) * potencia(k,n/2);
	else	
		return potencia(k,n/2) * potencia(k,n/2) * k;
}

/**
 * Testa a função pot.
 */
int main () {
	printf ("Teste 1: ");
	printf ("%d = %d \n", 4, potencia(2,2));
   
	printf ("Teste 2: ");
	printf ("%d = %d \n", 125, potencia(5,3));
   
	printf ("Teste 3: ");
	printf ("%d = %d \n", 32, potencia(2,5));

	printf ("Teste 4: ");
	printf ("%d = %d \n", 16, potencia(2,4));

	printf ("Teste 5: ");
	printf ("%d = %d \n", 100000, potencia(10,5));
   
	return 0;
}
