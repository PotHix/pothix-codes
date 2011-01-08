/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc exercicio3.c -o exercicio3 -Wall -O2 -ansi
 */

#include <stdio.h>

void peneira (int p, int m, int v[]){
 	int f=2*p, x=v[p];
	while(f<=m){
		if(f<m && v[f]<v[f+1])
		 	f++;
		if(x>=v[f]) break;
		v[p] = v[f];
		p=f; f=2*p;
	}
	v[p]=x;
}
/*
void peneira (int p, int m, int v[]){
 	int f=2*p, x=v[p];
	while(f<=m){
		if(f<m && v[f]<v[f+1])
		 	f++;
		if(x>=v[f]) break;
		v[p] = v[f];
		p=f; f=2*p;
	}
	v[p]=x;
}
*/
void heapsort(int n, int v[]){
	int p,m,x;
	for(p=n/2; p>=1; p--){
		peneira(p,n,v); 
	}
	for(m=n; m>=2; m--){
		x=v[1]; v[1]=v[m];
		v[m]=x;
		peneira(1,m-1,v);
	}
}

/* 
 * Heapsort do Paulo Feofiloff
 * 
 
 Recebe p em 1..m e rearranja o vetor v[1..m] de modo 
 que o "subvetor" cuja raiz é p seja um max-heap.
 Supõe que os "subvetores" cujas raízes são filhos
 de p já são max-heaps.
void peneira (int p, int m, int v[])
{
   int f = 2*p, x;
   while (f <= m) {
      if (f < m && v[f] < v[f+1])  ++f;
      /* f é o filho "mais valioso" de p
      if (v[f/2] >= v[f]) break;
      x = v[f/2], v[f/2] = v[f], v[f] = x;
      f *= 2;
   }
}

/*
 Rearranja os elementos do vetor v[1..n] 
 de modo que fiquem em ordem crescente
void heapsort (int n, int v[])
{
   int p, m, x;
   for (p = n/2; p >= 1; --p)
      peneira (p, n, v);
   for (m = n; m >= 2; --m) {
      x = v[1], v[1] = v[m], v[m] = x;
      peneira (1, m-1, v);
   }
}
*/ 


/**
 * Testa a função heapsort.
 */
int main () {
	int v[6], n=6,i;

	printf ("Teste 1: \n");
	v[0] = 0; v[1] = 5; v[2] = 4; v[3] = 3; v[4] = 2; v[5] = 1;

	for(i=0;i<n;i++){
		printf("%d ",v[i]); 
	}

	printf("\n "); 
	heapsort(6,v); 
	printf("\n"); 
	
	for(i=0;i<n;i++){
		printf("%d ",v[i]); 
	}

	printf("\n"); 

	return 0;
}
