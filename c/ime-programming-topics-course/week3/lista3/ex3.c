/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc exercicio.c -o exercicio -Wall -O2 -ansi
 */

#include <stdio.h>

/**
 * 
 *
 *
 */
int (int y, int ini, int fim, int v[]){
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
	printf ("%d = %d \n", 3, remove_todos(0, 0, 5, v));

	printf ("Teste 2: ");
	printf ("%d = %d \n", 3, remove_todos(4, 1, 5, v));

	printf ("Teste 3: ");
	printf ("%d = %d \n", 5, remove_todos(7, 0, 5, v));

	printf ("Teste 4: ");
	printf ("%d = %d \n", 2, remove_todos(2, 1, 4, v));

	printf ("Teste 5: ");
	printf ("%d = %d \n", 2, remove_todos(2, 0, 3, v));

	return 0;
}
