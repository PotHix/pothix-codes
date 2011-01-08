/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc soma_intervalor.c -o soma -Wall -O2 -ansi
 */

#include <stdio.h>

/**
 * FUNÇÃO RECEBE POSICAO DE INICIO, POSICAO DE FINAL E UM VETOR, E DEVOLVE A
 * SOMA DOS NUMEROS PARES DO VETOR NESSE INTERVALO
 */

int soma_intervalo (int ini, int fim, int v[]) {
	int i, soma=0;
	for (i=ini; i<=fim; i++){
		if(v[i]>0){
			soma+=v[i];
		}
	}
	return soma;
}

/*
INVARIANTE: 
	"soma contem a soma de todos os valores positivos do vetor v[ini] a v[i]"

inicialização:
	A variável soma é iniciada com 0 e a variavel i é iniciada com o valor de ini, portanto temos que "soma contem a soma de todos os valores positivos do vetor v[ini] a v[i]"
	
manutenção:
	Suponha que P(k) é verdadeiro. Vamos provar que P(k+1) tambem é verdadeiro.
	Na iteração em que P(k) vale temos que k=i, e "soma contem a soma de todos os valores positivos do vetor v[ini] a v[i]", da execução da linha 3 temos dois casos para analizar:
	Caso1: v[i]>0
		Nesse caso, a variável soma receberá o conteúdo de o conteúdo de v[i] e portanto teremos "soma contem a soma de todos os valores positivos do vetor v[ini] a v[i]". Agora a variável i será incrementada em 1, portanto vale P(k+1).
	Caso2: v[i]<0
		Nesse caso nada é executado e a invariante é mantida.

término: 
	O laço da linha 2 termina quando i>fim, portanto "soma contem a soma de todos os valores positivos do vetor v[ini] a v[i]"
*/ 
		

/**
 * Testa a função soma_intervalo.
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
