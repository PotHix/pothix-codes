#define ELEM 8
#include<stdio.h>

void selection(int n,int v[]){
	int min,i,j,aux;	

	for(i=0;i<n;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(v[j] < v[min]){
				min = j;	
			}
		}

		aux = v[min];
		v[min] = v[i];
		v[i] = aux;
	}
}

int main(){
	int v[ELEM],i;
	v[0]=3; v[1]=2; v[2]=4; v[3]=0; v[4]=7; v[5]=6; v[6]=8; v[7]=5;

	for(i=0;i<ELEM;i++){
		printf("%d",v[i]);
	}

	printf("\n");

	selection(ELEM, v);

	for(i=0;i<ELEM;i++){
		printf("%d",v[i]);
	}
	printf("\n");

	return 0;
}
