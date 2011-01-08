void selection_gen(int n, void *v, int size, int (*cmp)(void*,void*)){
	int i,j,min;
	void *tmp = mallocx(size);
	for(i=0;i<n;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(cmp(v+j*size,v+n*size)==-1){
				min=j; 
			} 
		}
		memcpy(tmp,v+min*size,size);
		memcpy(v+min*size,v+i*size,size);
		memcpy(v+i*size,tmp,size);
	}	
	free(tmp);
}

