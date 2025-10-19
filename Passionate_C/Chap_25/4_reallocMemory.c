#include<stdio.h>
#include<stdlib.h>

int main(){
	int *ptr = (int*)malloc(sizeof(int)*10);
	
	for(int i=0; i<10; i++)
		ptr[i] = i+1;
	
	for(int i=0; i<10; i++)
		printf("%d ", ptr[i]);
	printf("\n");
	
	ptr = realloc(ptr, sizeof(int)*20);
	
	for(int i=10; i<20; i++)
		ptr[i] = i+1;
	
	for(int i=0; i<20; i++)
		printf("%d ", ptr[i]);
	printf("\n");
	
	free(ptr);
	
	return 0;
}