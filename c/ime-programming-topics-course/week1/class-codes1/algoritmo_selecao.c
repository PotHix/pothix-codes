/*
   Este eh o cohdigo que fizemos em aula.

   Para compilar:
   g++ selecao.c -o seleaco

   Para executar:
   (no windows) selecao.exe
   (no linux) ./selecao

   Para interrompe a entrada de dados:
   CTRL+C 
*/   

#include <stdio.h>

#define MAX 10

/* PROTOTIPOS */
void selecao (int n, int v[]);

int main () {
   int n, i, v[MAX];

   for (n = 0; n < MAX; n++) {
      if (scanf ("%d", &v[n]) == EOF)
         break;
   }
   selecao (n, v);

   for (i = 0; i < n; i++) {
      printf ("%d ", v[i]);
   }
   printf ("\n");
   
   return 0;
}

void selecao (int n, int v[]) {
   int i, j, min, x;

   for (i = 0; i < n; i++) {
      min = i;
      for (j = i + 1; j < n; j++) {
         if (v[j] < v[i])
            min = j;
      }
      x = v[min]; v[min] = v[i]; v[i] = x;
   }
}



