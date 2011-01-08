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

void ordena_strings(int n, char s[50][51]){
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
 * Testa a função ordena_strings.
 */
int main () {
 	int v[6],i,n=6;
	v[0]=5; v[1]=4; v[2]=3; v[3]=2; v[4]=1; v[5]=0; 

   	for(i=0;i<n;i++){
		printf ("%d", v[i]);
	}

	printf ("\n");

	printf ("Teste 1:\n ");
	insertion(6,v);
   
   	for(i=0;i<n;i++){
		printf ("%d", v[i]);
	}

	printf ("\n");

	return 0;
}
