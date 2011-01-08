/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc exercicio.c -o exercicio -Wall -O2 -ansi
 */

#include <stdio.h>

/**
 * recebe um inteiro x, um vetor v, um inteiro para posição de inicio e um
 * inteiro para posição de fim. Devolve a posição de x no vetor, caso x não
 * esteja no vetor, devolve ini -1
 */
int busca_r(int x, int ini, int fim, int v[]){
 	if(v[fim] == x) return fim; 
 	if(ini == fim) return ini -1; 

	return busca_r(x,ini,--fim,v);
}


/**
 * Testa a função soma_digiros_r.
 */
int main () {
	int v[25];
	int i;

	/* Inicializando o vetor v */
	for (i = 0; i < 25; i++) {
		v[i] = 0;
	}

	printf ("Teste 1: ");
	v[0] = 0; v[1] = 2; v[2] = 0; v[3] = 4; v[4] = 6; v[5] = 9;
	printf ("%d = %d \n", 3, busca_r(4, 0, 5, v));

	printf ("Teste 2: ");
	printf ("%d = %d \n", 3, busca_r(4, 1, 5, v));

	printf ("Teste 3: ");
	printf ("%d = %d \n", -1, busca_r(7, 0, 5, v));

	printf ("Teste 4: ");
	printf ("%d = %d \n", 1, busca_r(2, 1, 4, v));

	return 0;
}
