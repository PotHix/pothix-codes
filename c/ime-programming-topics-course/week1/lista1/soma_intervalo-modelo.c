/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc soma_intervalor.c -o soma -Wall -O2 -ansi
 */

#include <stdio.h>

/**
 * FUNÇÃO RECEBE 
 */
int soma_intervalo (int ini, int fim, int v[]) {
   int i, soma;

   if (v[ini]>0){
      soma=v[ini];
   }else{
      soma=0;
   }
   for (i=ini+1;i<fim;i++){
      if(v[i]>0){
	 soma+=v[i];
      }
   }
   return soma;
} 


/**
 * Testa a função soma_intervalo.
 */
int main () {
   int v[100];
   int i;

   /* Inicializando o vetor v */
   for (i = 0; i < 100; i++) {
      v[i] = 0;
   }

   printf ("Teste 1: ");
   v[0] = 0; v[1] = 2; v[2] = 0; v[3] = 4; v[5] = 6;
   printf ("%d = %d \n", 12, soma_intervalo (0, 6, v));

   printf ("Teste 2: ");
   printf ("%d = %d \n", 4 + 6, soma_intervalo (3, 6, v));

   printf ("Teste 3: ");
   v[0] = 100; v[6] = 10;
   printf ("%d = %d \n", 122, soma_intervalo (0, 7, v)); 

   printf ("Teste 4: ");
   printf ("%d = %d \n", 0, soma_intervalo (6, 6, v));

   return -1;
}
