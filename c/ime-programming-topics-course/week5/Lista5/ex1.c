/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc exercicio1.c -o exercicio1 -Wall -O2 -ansi
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
	int conteudo;
	struct no *esq, *dir;
};

int conta_celulas(no *raiz){
	if(raiz == NULL )
		return 0;

	return 1 + conta_celulas(raiz->esq) +  conta_celulas(raiz->dir);
}

no *NO_novo(){
	no *p=mallocx(sizeof(no));
	p->esq = p->dir = NULL;

	return p;
}

int busca_r(int n, int v[], int x){
	int i=0;
	while(i<n && v[i]<x){
		i++; 
	}
	if(i<n && v[i] == x)
	 	return i;
	return -1; 
}

int busca_br(int v[], int e, int d, int x){
	int m;
	if(e>d) return -1;
	m=(e+d)/2;
	if(v[m] == x) return m;
	else if( v[m] < x)
	 	return busca_br(v, m+1, d, x);
	else
	 	return busca_br(v, e, m-1, x);
	 	
}

void red(no *r){
	if(r != NULL){
		printf("%d", r->conteudo);
		red(r->esq);
		red(r->dir);
	} 
}

void edr(no *r){
	if(r != NULL){
		edr(r->esq);
		edr(r->dir);
		printf("%d", r->conteudo);
	} 
}

no *primeiro(no *r){
	while(r->esq != NULL){
		r=r->esq; 
	} 
	return r;
}

/* A função recebe dois vetores v[0...n-1] e w[...n-1] que possuem as
 * varreduras em "pre-ordem" e "em-ordem" de uma arvore T, e imprime a
 * varredura em "pós-ordem" de T */
void posordem(int n, char v[], char w[]){
	if(n==0) return;
	int i;
	for(i=0; i<n; i++)
	 	if(w[i] == v[0]) break;
	if(i==0){
	 	/* então a subarvore da esq é vazia */	
		posordem(n-1, v+1, w+1);
	}else if(i==n-1){
	 	/* então a subarvore da dir é vazia */	
		posordem(n-1, v+1, w); 
	}	
	else{
		posordem(n-i-1, v+i+1, w+i+1); 
	}
	printf("%c", v[0]);
}

int main() {
	no *raiz = NO_novo();
	raiz->esq = NO_novo();
	raiz->dir = NO_novo();
	raiz->esq->esq = NO_novo();
	raiz->esq->dir = NO_novo();
	raiz->dir->dir = NO_novo();
	raiz->dir->esq = NO_novo();

	printf ("Teste 1: \n");

	printf("%d\n",conta_celulas(raiz));
	return 0;
}
