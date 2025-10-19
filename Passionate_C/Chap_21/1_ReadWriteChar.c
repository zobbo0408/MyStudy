#include<stdio.h>

int main(){
	int ch1, ch2;
	
	ch1 = getchar(); // 문자 입력
	ch2 = fgetc(stdin); // 엔터키 입력
	// 둘 다 키보드로부터 한 문자씩 입력을 받으며, 입력 스트림 "stdin"을 받음
	
	putchar(ch1);
	fputc(ch2, stdout);
	
	return 0;
}