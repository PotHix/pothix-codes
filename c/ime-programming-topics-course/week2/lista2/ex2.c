/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc exercicio.c -o exercicio -Wall -O2 -ansi
 */

#include <stdio.h>

/**
 * FUNÇÃO RECEBE POSICAO DE INICIO, POSICAO DE FINAL E UM VETOR, E DEVOLVE A
 * SOMA DOS NUMEROS PARES DO VETOR NESSE INTERVALO
 */

int nquad(int n){
	if(n==1){
		return n; 
	}else{
		return (nquad(n-1)^2) +2*n -1; 
	}
} 

/*
INDUCAO: 
*/ 
		

/**
 * Testa a função nquad.
 */
int main () {
	printf ("Teste 1: ");
	printf ("%d = %d \n", 25, nquad(5));
	
	printf ("Teste 2: ");
	printf ("%d = %d \n", 100, nquad(10));
	
	printf ("Teste 3: ");
	printf ("%d = %d \n", 81, nquad(9));
	
	printf ("Teste 4: ");
	printf ("%d = %d \n", 36, nquad(6));
	
	return 0;
}
