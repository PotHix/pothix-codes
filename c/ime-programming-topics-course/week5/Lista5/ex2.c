/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc exercicio2.c -o exercicio2 -Wall -O2 -ansi
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

typedef struct no no;
struct no{
	int chave;
	int conteudo;
	struct no *esq, *dir;
};

int min(no *raiz){
	if(raiz->esq == NULL) return raiz->chave;
	return min(raiz->esq);
}

no *NO_novo(chave){
	no *p=mallocx(sizeof(no));
	p->esq = p->dir = NULL;
	p->chave = chave;

	return p;
}



/**
 * Testa a função inversoes.
 */
int main () {
	no *raiz = NO_novo(10);
	raiz->esq = NO_novo(5);
	raiz->dir = NO_novo(20);
	raiz->esq->esq = NO_novo(3);
	raiz->esq->dir = NO_novo(9);
	raiz->dir->dir = NO_novo(30);
	raiz->dir->esq = NO_novo(19);
	raiz->dir->dir->dir = NO_novo(31);

	printf ("Teste 1: \n");

	printf("%d\n",min(raiz));
	return 0;
}
