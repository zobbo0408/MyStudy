#include<stdio.h>

int main(){
	char * str = "Simple String";
	
	printf("1. puts test ----------\n");
	puts(str);								// 문자열 출력 함수
	printf("\n");
	
	printf("2. fputs test ---------\n");
	fputs(str, stdout);						// 문자열 출력 함수, 파일 스트림 지정 필요
	printf("\n");
	
	return 0;
}