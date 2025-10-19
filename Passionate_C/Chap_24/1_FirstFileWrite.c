#include<stdio.h>

int main(){
	FILE *fp = fopen("data.txt", "wt");	// FILE은 반환형 구조체, 즉 파일 구조체이다.
	// wt는 출력 스트림이다
	if(fp == NULL){
		puts("파일 오픈 실패!");
		return -1;
	}
	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);
	fclose(fp);		// 스트림의 종료
	return 0;
}