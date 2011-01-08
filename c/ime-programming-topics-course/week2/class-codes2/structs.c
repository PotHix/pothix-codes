#include<stdio.h>
typedef struct celula celula;
struct celula{
	int inteiro;
	char caractere[10];
};


int main(){
	celula teste;
	teste.inteiro = 10;

	printf("%d",teste.inteiro);
	printf("\n");

	celula *p_teste = malloc(sizeof(celula));

	p_teste->inteiro = 40;

	printf("%d",p_teste->inteiro);
	printf("\n");
	return 0;
}
