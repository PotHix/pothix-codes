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
int busca(int n, int v[]){
 	int i;
	for(i=0; i<n; i++){
		if(v[i] == i) return i; 
	}
	return -1;
}


/**
 * Testa a função pot.
 */
int main () {
 	int v[9];
	v[0]=1;v[1]=2;v[2]=2;v[3]=4;v[4]=5;v[5]=6;v[6]=7;v[7]=8;v[8]=9;

	printf ("Teste 1: ");
	printf ("%d = %d \n", -1, busca(9,v));
   
	printf ("Teste 2: ");
	printf ("%d = %d \n", -1, busca(9,v));
   
	printf ("Teste 3: ");
	printf ("%d = %d \n", -1, busca(9,v));

	printf ("Teste 4: ");
	printf ("%d = %d \n", -1, busca(9,v));

	printf ("Teste 5: ");
	printf ("%d = %d \n", -1, busca(9,v));
   
	return 0;
}
