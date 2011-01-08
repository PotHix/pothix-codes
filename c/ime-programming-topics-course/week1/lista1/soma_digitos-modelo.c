/**
 * Nome do aluno.: Willian Araujo Molinari
 * E-mail........: willian.molinari@gmail.com
 *    gcc soma_digitos.c -o somad -Wall -O2 -ansi
 */

#include <stdio.h>

/**
 * FUNÇÃO QUE RECEBE UM INTEIRO E DEVOLVE A SOMA DOS DIGITOS DESSE INTEIRO
 */
int soma_digitos(int n) {
   int soma=0, numero_digitos=n;
   while(numero_digitos>0) {
      soma+=(numero_digitos%10);
      numero_digitos/=10; 
   }
   return soma;
} 

/**
 * Testa a função soma_intervalo.
 */
int main () {
   printf ("Teste 1: ");
   printf ("%d = %d \n", 1, soma_digitos (10));

   printf ("Teste 2: ");
   printf ("%d = %d \n", 0, soma_digitos (00000));

   printf ("Teste 3: ");
   printf ("%d = %d \n", 43, soma_digitos (999912310));

   return 0;
}
