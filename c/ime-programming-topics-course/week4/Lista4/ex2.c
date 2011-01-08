/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc exercicio2.c -o exercicio2 -Wall -O2 -ansi
 */

#include <stdio.h>

/**
 * Recebe um inteiro n e um vetor de tamanho v[n] e devolve a quantidade de
 * inversoes ( i<j e v[i]>v[j]) contidas no vetor
 */
int inversoes (int n, int v[]){
 	int inv=0,i,j;
	for(i=0; i<n; i++){
		for(j=n-1; j>i; j--){
			if(i<j && v[i]>v[j]) inv++; 
		} 
	}
	return inv;
}

/**
 * Testa a função inversoes.
 */
int main () {
	int v[6];
	int i,n=6;

	/* Inicializando o vetor v */
	for (i = 0; i < 6; i++) {
		v[i] = 0;
	}

	printf ("Teste 1: \n");
	v[0] = 9; v[1] = 2; v[2] = 0; v[3] = 4; v[4] = 6; v[5] = 9;

	for(i=0;i<n;i++){
		printf("%d ",v[i]); 
	}

	printf("\n "); 

	printf("%d \n", inversoes(6,v)); 

	
	return 0;
}
