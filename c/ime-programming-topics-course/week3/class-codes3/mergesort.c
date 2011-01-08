/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc exercicio.c -o exercicio -Wall -O2 -ansi
 */

#include <stdio.h>
#include <stdlib.h>

void *mallocx(int num_bytes){
	void *p = malloc(num_bytes);
	if(p==NULL){
		printf("ERRO: Memória insuficiente");
		exit(1);
	}
	return p;
}

/* A função recebe vetores crescentes v[p...q-1] e v[q...r-1] e rearranja
 * v[p...r-1] em ordem crescente */
void intercala(int p, int q, int r, int v[]){
	int i, j, k, *w;
	w = mallocx(sizeof(int) * (r-p));
	i=p; j=q; k=0;
	while(i<q && j<r){
	 	if(v[i] <= v[j]) w[k+1] = v[i++];
		else w[k++] = v[j++];
	}
	while(i<q) w[k++] = v[i++];
	while(j<q) w[k++] = v[j++];
	for(i=p; i<r; i++) v[i] = w[i-p];
	free(w);
}

/**
 * recebe um inteiro y, um vetor v, um inteiro para posição de inicio e um
 * inteiro para posição de fim. Devolve a posição de x no vetor, caso x não
 * esteja no vetor, devolve ini -1
 */
void mergesort(int p, int r, int v[]){
 	if(r-p <= 1) return;
	else {
		int q=(p+r)/2;
		mergesort(p,q,v);
		mergesort(p,r,v);
		intercala(p,q,r,v);
	}
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
/*
	printf ("Teste 1: ");
	v[0] = 0; v[1] = 2; v[2] = 0; v[3] = 4; v[4] = 6; v[5] = 9;
	printf ("%d = %d \n", 4, mergesort(0, 0, 5, v));

	printf ("Teste 2: ");
	printf ("%d = %d \n", 4, mergesort(4, 1, 5, v));

	printf ("Teste 3: ");
	printf ("%d = %d \n", 6, mergesort(7, 0, 9, v));

	printf ("Teste 4: ");
	printf ("%d = %d \n", 3, mergesort(2, 1, 4, v));
*/
	return 0;
}
