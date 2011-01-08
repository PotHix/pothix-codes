/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc exercicio1.c -o exercicio1 -Wall -O2 -ansi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mallocx(int num_bytes){
	void *p = malloc(num_bytes);
	if(p==NULL){
		printf("ERRO: memória insuficiente");
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

void PILHA_empilha(pilha *p,char x){
	p->elem[p->topo++] = x;
}

void PILHA_desempilha(pilha *p){
	p->topo--;
}

char PILHA_topo(pilha *p){
	return p->elem[p->topo-1];
}

int PILHA_vazia(pilha *p){
	return (p->topo == 0)?1:0;
}

int PILHA_cheia(pilha *p){
	return (p->topo == p->max)?1:0;
}

/**
 * Recebe uma frase e retorna as palavras invertidas
 * Ex: "exemplo muito facil" -> "olpmexe otium licaf"
 */
void inverte(char frase[]){
 	int i,j=0;

	pilha *p=PILHA_nova(strlen(frase));

	for(i=0;frase[i]; i++){
	 	if(frase[i] != ' ') PILHA_empilha(p,frase[i]);
		else {
			while(!PILHA_vazia(p)){
				frase[j++] = PILHA_topo(p); 
				PILHA_desempilha(p);
			}
			frase[j++] = ' ';
		}
	}
	/* Encontrar uma forma melhor para isso */
	while(!PILHA_vazia(p)){
		frase[j++] = PILHA_topo(p); 
		PILHA_desempilha(p);
	}
	frase[j++] = ' ';
	/* Fim do código duplicado */

	PILHA_mata(p);
}

/**
 * Testa a função inverte.
 */
int main() {
	char frase[] = "este exercicio eh muito facil\0";

	printf ("Teste 1: \n");
	printf("%s",frase);

	inverte(frase);
	printf("\n");

	printf("%s",frase);
	printf("\n");

	return 0;
}
