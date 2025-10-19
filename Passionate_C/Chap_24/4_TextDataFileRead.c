#include<stdio.h>

int main(){
	char str[30];
	int ch;
	
	FILE * fp = fopen("simple.txt", "rt");
	if(fp == NULL){
		puts("파일오픈 실패!");
		return -1;
	}
	
	ch = fgetc(fp);
	printf("%c\n", ch);
	ch = fgetc(fp);
	printf("%c\n", ch);
	
	fgets(str, sizeof(str), fp);
	printf("%s", str);			// txt파일엔 이미 \n이 포함되었기에 프린트 함수에 쓰지 않아도 알아서 개행됨.새ㅕ초 
	fgets(str, sizeof(str), fp);
	printf("%s\n", str);
	
	fclose(fp);
	
	return 0;
}