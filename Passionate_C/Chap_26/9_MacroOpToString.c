#include<stdio.h>
#define STRING_JOB(A, B)	#A "의 직업은 " #B "입니다."

int main(){
	printf("%s\n", STRING_JOB(박준영, 군인));
	return 0;
}