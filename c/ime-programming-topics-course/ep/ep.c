/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc ep.c -o ep -Wall -O2 -ansi
 */

#define TAM_P 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula celula;
struct celula{
	char palavra[TAM_P];
	celula *prox;
};

/* Função recebe um vetor de caracteres e devolve um ponteiro para um espaço
 * de memória com uma celula alocada com o valor do vetor de caracteres em
 * seu conteudo "palavra" */
celula *CELULA_nova(char palavra[]){
	celula *p = malloc(sizeof(celula));
	if(p==NULL){
		printf("ERRO: memória insuficiente");
		exit(1);
	}
	strcpy(p->palavra,palavra);
	p->prox=NULL;
	return p;
}

/* Função recebe um vetor de caracteres e uma celula p e insere uma nova
 * celula com o conteudo de palavra na frente da celula p*/
void CELULA_insere(char palavra[], celula *p){
	celula *q = CELULA_nova(palavra);
	q->prox=p->prox;
	p->prox=q;
}

/* Recebe dois vetores de caracteres e devolve 1 caso as strings sejam
 * anagramas uma da outra, e 0 caso contrário */
int verifica_anagramas(char string1[], char string2[]){
	int i,j,aux1=0,aux2=0;

	/* Caso os tamanhos não sejam iguais não gasta processamento */
	if(strlen(string1) == strlen(string2)){
		/* Todas as letras da string1[0...i-1] estão presentes na mesma quantidade na string2  */
		for(i=0; i<strlen(string2); i++,aux1=0,aux2=0){
			/* aux1 e aux2 são a quantidade de letras iguais a string1[i] que estão presentes em string1 e string2 respectivamente */
			for(j=0; j<strlen(string2); j++){
				if(string1[i] == string1[j]){
					aux1++; 
				} 
				if(string1[i] == string2[j]){
					aux2++; 
				} 
			}	
			if(aux1 != aux2) return 0;
		} 
		return 1;
	}	
	return 0;

}

/* Recebe um vetor de caracteres "palavra" e um ponteiro p para uma celula de uma lista encadeada, e devolve
 * o endereço de uma celula que contem o conteudo de "palavra". Se não existir tal celula a
 * função devolve NULL */
celula *CELULA_busca_anagrama(char palavra[], celula *p){
 	if(p->prox==NULL)
	 	return NULL;
	if(verifica_anagramas(palavra,p->prox->palavra))
	 	return p->prox;
	return CELULA_busca_anagrama(palavra,p->prox);	
}

/* Recebe um ponteiro para a cabeça de uma lista e cria uma lista
 * encadeada de acordo com valores requisitados pela entrada padrão */
void criaLista(celula *cabeca){
	char palavra_aux[TAM_P];
	celula *celula_lista = cabeca;

	printf("Digite uma palavra por linha, e quando acabarem as palavras a serem digitadas, apenas aperte enter para uma linha em branco\n");

	/* Todas as celulas que contem palavras que são anagramas de outras estão seguidas ou precedidas de uma celula que contem seu anagrama */
	while(strlen(fgets(palavra_aux, TAM_P, stdin)) != 1){ 
		palavra_aux[strlen(palavra_aux)-1]='\0'; /* Altera o ultimo caractere a palavra de \n para \0 */
		celula_lista = CELULA_busca_anagrama(palavra_aux, cabeca);
		if(celula_lista == NULL){ 
			CELULA_insere(palavra_aux,cabeca);
		}else{
			CELULA_insere(palavra_aux,celula_lista);
		}
	}
}

int main(){
	celula *cabeca = CELULA_nova("");

	criaLista(cabeca);
	celula *celula_print = cabeca->prox;

	printf("\n");
	while(celula_print->prox != NULL){
	 	if(verifica_anagramas(celula_print->palavra, celula_print->prox->palavra)){
			printf("%s ",celula_print->palavra);
		}else{
			printf("%s\n",celula_print->palavra);
		} 
		celula_print = celula_print->prox;
	}
	printf("%s\n",celula_print->palavra);

	return 0;	
}
