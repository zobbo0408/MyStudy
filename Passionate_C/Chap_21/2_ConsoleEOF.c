#include<stdio.h>

int main(){
	int ch;
	while(1){
		ch = getchar();
		if(ch == EOF)
			break; // C언어에선 EOF는 Ctrl+Z, EOF는 -1로 정의된 상수.
				   // 그렇기에 getchar(), 또는 fgetc(FILE * stream)은 int형으로 받는다.
		putchar(ch);
	}
	
	return 0;
}