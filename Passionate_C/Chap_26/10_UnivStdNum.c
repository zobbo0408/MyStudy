#include<stdio.h>
//#define STNUM(Y, S, P)	((Y)*100000+(S)*1000+P)
#define STNUM(Y, S, P)	Y ## S ## P

int main(){
	printf("학번 : %d\n", STNUM(10, 65, 175)); // 결과 1065175 (이상적)
	printf("학번 : %d\n", STNUM(10, 65, 075)); // 결과 1065061 (앞의 0은 8진수를 나타내서 061이 됨.)
	return 0;
}