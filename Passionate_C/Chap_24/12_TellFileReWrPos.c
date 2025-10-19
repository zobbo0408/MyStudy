#include<stdio.h>

int main(){
	long fpos;
	int i;
	
	FILE * fp = fopen("text2.txt", "wt");
	fputs("1234-", fp);
	fclose(fp);
	
	FILE * fpp = fopen("text2.txt", "rt");
	
	for(i=0; i<4; i++){
		putchar(fgetc(fpp));
		fpos = ftell(fpp);
		fseek(fpp, -1, SEEK_END);
		putchar(fgetc(fpp));
		fseek(fpp, fpos, SEEK_SET);
	}
	
	printf("\n");
	
	fclose(fpp);
	
	return 0;
}