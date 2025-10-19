#include<stdio.h>

int main(){
	FILE * src = fopen("simple.txt", "rt");
	FILE * dst = fopen("dst.txt", "wt");
	char str[30];
	
	if(src == NULL || dst == NULL){
		puts("파일오픈 실패!");
		return -1;
	}
	
	// fgets함수는 줄을 읽으면서 널 값인지 확인
	while(fgets(str, sizeof(str), src) != NULL){
		fputs(str, dst);
	}
	// 파일의 끝을 확인해주는 함수 feof(), 끝에 도달한다면 0이 아닌 값을 내놓는다.
	if(feof(src) != 0){
		puts("파일복사 완료!");
	}
	else{
		puts("파일복사 실패!");
	}
	
	fclose(src);
	fclose(dst);
	
	return 0;
}