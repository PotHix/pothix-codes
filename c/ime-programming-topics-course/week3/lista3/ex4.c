/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc exercicio.c -o exercicio -Wall -O2 -ansi
 */

#include <stdio.h>

/**
 * Recebe um vetor de tamanho n e ordena o mesmo
 */
void bolhas (int n, int v[]){
 	int x,i,j;
	for(i=0; i<n; i++){
		for(j=n-1; j>i; j--){
			if(v[j] < v[j-1]){
				x=v[j];
				v[j] = v[j-1];
				v[j-1] = x;
			} 
		} 
	}
}

/*
 * INVARIANTE1:
 * 		Todos os numeros de v[0..i-1] estão ordenados
 *
 * 		INICIALIZAÇÃO: temos que i é inicializado com 0, portanto como v[0..i-1] é vazio, nossa invariante se mantem.
 *
 * 		MANUTENÇÃO: Suponha que p(k) vale então vamos provar que p(k+1) tambem vale. Na iteração em que p(k) vale, temos que i=k e v[k] é o menor numero do vetor v[j..n-1]. Supondo que a linha 3 retorne o esperado, teremos que i será o menor numero do vetor v[j...n-1] portanto, após o incremento teremos que todos os numeros de v[0..i-1] estão ordenados
 *
 *		TERMINO: o laço da linha 2 termina quando i=n, portanto temos que todos os numeros de v[0..i-1] estão ordenados
 * 		
 * INVARIANTE2:		
 *		v[j] é o menor numero do vetor v[j..n-1]
 *
 * 		INICIALIZAÇÃO: temos que j recebe o valor de n-1, portanto v[j] é o menor numero do vetor v[j...n-1], pois há apenas 1 numero
 *
 * 		MANUTENÇÃO: Suponha que p(k) vale então vamos provar que p(k-1)	tambem vale. Na iteração em que p(k) vale, temos que j=k e v[k]	é o menor numero do vetor v[j..n-1]. Da execução da linha 4	temos 2 casos para analizar:
 * 		caso1: v[j]<v[j-1], portanto faremos a troca de posições entre v[j] e v[j-1] e logo após teremos que j será decrementado, portanto v[j] é o menor numero do vetor v[j...n-1]
 * 		caso2: v[j]>v[j-1], nada será executado e após o decremento a nossa invariante se mantem.
 *
 *		TERMINO: o laço da linha 3 termina quando j=i, portanto temos que j é o menor numero do vetor v[j..n-1].
 */ 

/**
 * Testa a função bolhas.
 */
int main () {
	int v[25];
	int i,n=6;

	/* Inicializando o vetor v */
	for (i = 0; i < 25; i++) {
		v[i] = 0;
	}

	printf ("Teste 1: \n");
	v[0] = 0; v[1] = 2; v[2] = 0; v[3] = 4; v[4] = 6; v[5] = 9;

	for(i=0;i<n;i++){
		printf("%d ",v[i]); 
	}

	bolhas(6,v);
	printf("\n"); 

	for(i=0;i<n;i++){
		printf("%d ",v[i]); 
	}

	printf("\n"); 

	return 0;
}
