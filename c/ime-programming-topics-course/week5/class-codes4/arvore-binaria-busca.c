/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc exercicio1.c -o exercicio1 -Wall -O2 -ansi
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct no no;
struct no{
	int chave;
	int conteudo;
	struct no *esq, *dir;
}

no *busca_r(no *r, int k){
 	if(r == NULL || r->chave == k){
		return r; 
	}
	if(r->chave > k)
	 	return busca(r->esq,k);
	else
	 	return busca(r->dir,k);
	 	
}

no *busca_i(no *r, int k){
 	while( r != NULL && r->chave != k ){
		if(r->chave > k)
		 	r=r->esq;
		else
		 	r=r->dir;
	}
	return r;
}

/* A função recebe uma arvore de busca r e um nó novo que não pertence a
 * arvore. A função insere o nó na arvore e devolve o endereço da nova
 * arvore de busca que contem o novo nó */
no *insere(no *r, no *novo){
	no *f, *p;
	if(i==NULL) return novo;
	f=r;
	while(f != NULL){
		p=f;
		if(f->chave > novo->chave)
		 	f=f->esq;
		else
		 	f=f->dir;
	}
	if(p->chave > novo->chave)
	 	r->esq = novo;
	else
	 	p->dir = novo;
	return r;	
}

no *insere_r(no *r, no *n){
	if(r==NULL)
	 	return n;
	if(r->chave > n->chave)
	 	r->esq = insere_r(r->dir, n)
	return r;	
}

no *removeraiz(no *r){
	no *p, *q;
	if(r->esq == NULL){
		q=r->dir;
		free(r);
		return q;
	}
	p=r; q=r->esq;
	while(q->dir != NULL){
		p=q; q=q->dir; 
	}
	if(p != r){
		p->dir = q->esq; 
		p->esq = q->esq; 
	}
	q->dir = r->dir;
	free(r);
	return q;
}

int main() {
	char frase[] = "este exercicio eh muito facil\0";

	printf ("Teste 1: \n");
	printf("%s",frase);

	printf("\n");

	printf("%s",frase);
	printf("\n");

	return 0;
}
