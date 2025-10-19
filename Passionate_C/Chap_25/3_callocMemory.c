#include<stdio.h>
#include<stdlib.h>

int main(){
	int * ptr1 = (int*)malloc(sizeof(int) * 10);
	int * ptr2 = (int*)calloc(10, sizeof(int));
	
	for(int i =0; i<10; i++){
		ptr1[i] = i+1;
		ptr2[i] = (i+1)*10;
	}
	
	for(int i=0; i<10; i++)
		printf("%d ", ptr1[i]);
	printf("\n");
	
	for(int i=0; i<10; i++)
		printf("%d ", ptr2[i]);
	printf("\n");
	
	free(ptr1);
	free(ptr2);
	
	return 0;
}