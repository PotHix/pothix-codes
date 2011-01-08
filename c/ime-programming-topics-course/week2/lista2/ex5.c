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

void insercao2(int n, int v[]){
	int i,x,j;
	for(i=1;i<n;i++){
		x=v[i];
		for(j=i-1;j>=0 && v[j]>x;j--){
			v[j+1] = v[j];
		}
		v[j+1] = x;
	}
}


/**
 * Testa a função insercao2.
 */
int main () {
	int v[100];
	int i;

	/* Inicializando o vetor v */
	for (i = 0; i < 100; i++) {
		v[i] = 0;
	}

	printf ("Teste 1: ");
	v[0] = 0; v[1] = 2; v[2] = 0; v[3] = 4; v[5] = 6;
	printf ("%d = %d \n", 12, soma_intervalo (0, 6, v));

	printf ("Teste 2: ");
	printf ("%d = %d \n", 4 + 6, soma_intervalo (3, 6, v));

	printf ("Teste 3: ");
	v[0] = 100; v[6] = 10;
	printf ("%d = %d \n", 122, soma_intervalo (0, 7, v)); 

	printf ("Teste 4: ");
	printf ("%d = %d \n", 0, soma_intervalo (6, 6, v));

	printf ("Teste 5: ");
	printf ("%d = %d \n", 10, soma_intervalo (2, 5, v));
	
	return 0;
}
