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

typedef struct pilha pilha;
struct pilha{
	int *elem;
	int max, topo;
};

pilha *PILHA_nova(int tm){
	pilha *p=malloc(sizeof(pilha));
	p->elem=malloc(sizeof(int)*tm);
	p->topo=0;
	p->max=tm;

	return p;
}

void PILHA_mata(pilha *p){
	free(p->elem);
}

void PILHA_empilha(pilha *p, int x){
	p->elem[p->topo++] = x;
}

void PILHA_desempilha(pilha *p){
	p->topo--;
}

char PILHA_topo(pilha *p){
	return p->elem[p->topo-1];
}

int PILHA_vazia(pilha *p){
	return (p->topo==0)?1:0;
}

int PILHA_cheia(pilha *p){
	return (p->topo == p->max)?1:0;
}

/*
 * FUNCAO RECEBE UM VETOR E V[0..N-1] DE CARACTERES E DEVOLVE 1 SE V EH UMA
 * EXPRESSAO BEM FORMADA E 0 CASO CONTRARIO
 */ 

int bemformada(int n, char v[]){
	int i; 
	pilha *p=PILHA_nova(n);
	for(i=0;i<n;i++){
		switch(v[i]){
			case ']':
				if(PILHA_vazia(p) || PILHA_topo(p) != '[')
					return 0;
				PILHA_desempilha(p);
				break;

			case ')':
				if(PILHA_vazia(p) || PILHA_topo(p) != '('){
					return 0;
				}
				else
				 	PILHA_desempilha(p);
				break;

			default:
				PILHA_empilha(p,v[i]);
				printf("%c \n",v[i]);
		}	
	}
	if (PILHA_vazia(p)){
		PILHA_mata(p);
		return 1;
	} else {
		PILHA_mata(p);
		return 0;
	}
}	

int main(){
	int r;
	char v[8];
	v[0]='[';v[1]='(';v[2]='[';v[3]='(';v[4]=')';v[5]=']';v[6]=')';v[7]=']';

	r = bemformada(8,v);

	printf("%d",r);
	return 0;
}
