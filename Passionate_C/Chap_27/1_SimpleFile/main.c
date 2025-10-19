#include<stdio.h>

extern void Increment();
extern int Getnum();	

int main(){
	printf("num : %d\n", Getnum());
	Increment();
	printf("num : %d\n", Getnum());
	Increment();
	printf("num : %d\n", Getnum());
	Increment();
	
	return 0;
}