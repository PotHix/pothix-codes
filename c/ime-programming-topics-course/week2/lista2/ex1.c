/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc exercicio.c -o exercicio -Wall -O2 -ansi
 */

#include <stdio.h>

/**
 * FUNÇÃO QUE RECEBE UM INTEIRO E DEVOLVE A SOMA DOS DIGITOS DESSE INTEIRO
 */
int soma_digitos_r(int n){
	if(n<=0) {return 0;}	
	int soma = n%10;

	return soma + soma_digitos_r(n/10);
}

/*
PROVA: 
	BASE: Caso n<=0 o retorno será 0, portanto, soma recebe uma adição do ultimo dígito
	Supondo que a base (k-1) é válida, temos que a cada chamada temos o retorno do ultimo digito do numero, assim temos que N tambem é válido.
*/ 
		

/**
 * Testa a função soma_digiros_r.
 */
int main () {
	printf ("Teste 1: ");
	printf ("%d = %d \n", 15, soma_digitos_r (528));
	
	printf ("Teste 2: ");
	printf ("%d = %d \n", 18, soma_digitos_r (936));
	
	printf ("Teste 3: ");
	printf ("%d = %d \n", 9, soma_digitos_r (333));
	
	printf ("Teste 4: ");
	printf ("%d = %d \n", 16, soma_digitos_r (529));
	
	return 0;
}
