#include<stdio.h>

int main(){
	FILE * src = fopen("data.txt", "rt");
	FILE * dst = fopen("dst.txt", "wt");
	int ch;
	
	if(src == NULL || dst == NULL){
		puts("파일오픈 실패!");
		return -1;
	}
	
	// fgetc는 파일의 끝에 도착했는지로 확인
	while((ch = fgetc(src)) != EOF){
		fputc(ch, dst);
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