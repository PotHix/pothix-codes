#define ELEM 8
#include<stdio.h>

void insertion(int n,int v[]){
	int i,j,x;

	for(i=1;i<n;i++){
		/*x=v[i];
		for(j=i-1;j>=0 && v[j]>x;j--){
			v[j+1] = v[i];
		}	
		v[j+1] = x;
		*/

		for(j=i-1;j>=0 && v[j+1]<v[j];j--){
			x=v[j];v[j]=v[j+1];v[j+1]=x;	
		}
			
	}
}

int main(){
	int v[ELEM],i;
	v[0]=3; v[1]=2; v[2]=4; v[3]=0; v[4]=7; v[5]=6; v[6]=8; v[7]=5;

	for(i=0;i<ELEM;i++){
		printf("%d",v[i]);
	}

	printf("\n");

	insertion(ELEM, v);

	for(i=0;i<ELEM;i++){
		printf("%d",v[i]);
	}
	printf("\n");

	return 0;
}
