#include<stdio.h>
#include<stdlib.h>
typedef struct celula celula;

struct celula{
	int conteudo;
	celula *prox;
};

/* A função recebe um inteiro x e uma lista encadeada(com cabeça) e devolve
 * o dendereço de uma celula que contem x. Se não existir tal velula a
 * função devolve NULL */
celula *busca(int x, celula *ini){
 	celula *p = ini->prox;
	while(p!=NULL && p->conteudo != x){
		p = p->prox;
	}
	return p;
}

celula *busca_r(int x, celula *p){
 	if(p->prox==NULL)
	 	return NULL;
	if(p->prox->conteudo == x)
	 	return p->prox;
	return busca_r(x,p->prox);	
}

celula *nova(int x){
	celula *p = malloc(sizeof(celula));
	if(p==NULL){
		printf("ERRO: Memória insuficiente"); 
		exit(1);
	}
	p->conteudo=x;
	p->prox=NULL;
	return p;
}

void insere(int x, celula *p){
	celula *q = nova(x);
	q->prox=p->prox;
	p->prox=q;
}

/* A função recebe um endereço de uma celula p e remove da lista o elemento
 * p->prox */
void remove_celula(celula *p){
	celula *q = p->prox;
	p->prox = q->prox;
	free(q);
}

/* A função recebe um endereço da cabeça de uma lista e insere uma nova
 * celula com conteudo x no inicio da lista */
void insere_inicio(celula *ini,int x){
	insere(x,ini); 
}

/* A função recebe um endereço da cabeça de uma lista encadeada e insere uma nova
 * celula com conteudo x no fim da lista */
void insere_fim(celula *ini, int x){
	celula *u=ini->prox;
	if(u==NULL){
		insere(x,ini);
		return;
	}
	while(u->prox !=NULL){
		u=u->prox; 
	}
	insere(x,u);
}

/* A função remove da lista com cabeça, a primeira celula. Se a lista
 * estiver vazia a função não faz nada */
void remove_inicio(celula *ini){
	if(ini->prox!=NULL){
		remove_celula(ini); 
	} 
}

/* A função remove a ultima celula da lista encadeada. Se a lista estiver
 * vazia a função não faz nada */
void remove_fim(celula *ini){
	celula *p;
	if(ini->prox != NULL){
		p=ini;
		while(p->prox->prox != NULL){
			p=p->prox; 
		}
		remove_celula(p);
	}
}

int main(){
	celula ini;
	ini.prox=NULL;

	insere_fim(&ini,15);
	insere_fim(&ini,25);
	insere_fim(&ini,35);
	insere_fim(&ini,45);

	insere_inicio(&ini,7);
	insere_fim(&ini,1);
	remove_inicio(&ini);
	remove_fim(&ini);

	celula *t;
	for(t=ini.prox; t!=NULL; t=t->prox){
		printf("%d\n",t->conteudo);
	}

	return 0;	
}
