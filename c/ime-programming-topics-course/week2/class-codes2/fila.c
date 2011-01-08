#include <stdio.h>
#include <stdlib.h>

#define N_MAX 100

void *mallocx(int num_bytes){
	void *p = malloc(num_bytes);
	if(p==NULL){
		printf("ERRO: Memória insuficiente");
		exit(1);
	}
	return p;
}

typedef struct fila fila;
struct fila{
	int *elem;
	int ini, fim, tam_max;
};

/* A função devolve uma nova fila com capacidade tam_max */
fila *FILA_nova(int tam_max){
	fila *f = (fila*)mallocx(sizeof(fila));
	f->elem = (int*)mallocx(sizeof(int)*tam_max);
	f->ini = f->fim=0;
	f->tam_max = tam_max;

	return f;
}

void FILA_insere(fila *f, int x){
	f->elem[f->fim++]=x;
}

void FILA_remove(fila *f){
	f->ini++;
}

int FILA_primeiro(fila *f){
	return f-> elem[f->ini];
}

int FILA_vazia(fila *f){
	return (f->ini == f->fim)?1:0;
}

int FILA_cheia(fila *f){
	return (f->fim == f->tam_max)?1:0;
}

/* Recebe uma matriz A que representa as estradas entre as cidades
 * 0,1,2,...,n; Há uma estrada ( de mão única) de i a j se e somente se A[i][j]==1.
 * A função devolve um vetor d que contem as distancias da cidade c a cada uma das outras */
int *distancias(int a[N_MAX][N_MAX], int n, int c){
	int *d,j,i;
	fila *f = FILA_nova(n);
	d=(int*)mallocx(n*sizeof(int));
	for(j=0;j<n;j++)
	 	d[j]=-1;
	FILA_insere(f,c);
	d[c]=0;
	while(!FILA_vazia(f)){
		i=FILA_primeiro(f);
		for(j=0;j<n;j++){
			if(a[i][j] == 1 && d[j]== -1){
				d[j] = d[i]+1;
				FILA_insere(f,i);
			} 
		}
	}
	return d;
}

int main(){
	return 0;
}
