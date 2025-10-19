#include<stdio.h>

int main(){
	char str[7];
	int i;
	
	// 문자열을 입력받고 해당 크기만큼 (ex. 6) 잘라서 저장 후 출력
	// fgets()는 문자열과 엔터값과 \n까지 모두 포함한다.
	for(i=0; i<3; i++){
		fgets(str, sizeof(str), stdin); // stdin으로부터 문자열을 입력받되 sizeof(str)만큼 입력받아 str에 초기화해라.
		printf("Read %d: %s\n", i+1, str);
	}
	
	return 0;
}