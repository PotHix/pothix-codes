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

int minimo_r2(int n. int v[]){
	if(n==1){return 0};
	int x= minimo_r(n/2-1,v);
	int x= minimo_r(n-1,v);
	if(v[n-1] < v[x]){
		return n-1; 
	} else {
		return x; 
	}
}

/**
 * Testa a função minimo_r2.
 */
int main() {
	int v[25];
	int i;

	/* Inicializando o vetor v */
	for (i = 0; i < 25; i++) {
		v[i] = 0;
	}

	printf ("Teste 1: ");
	v[0] = 0; v[1] = 2; v[2] = 0; v[3] = 4; v[5] = 6;
	printf ("%d = %d \n", 0, minimo_r2(6, v));

	return 0;
}
