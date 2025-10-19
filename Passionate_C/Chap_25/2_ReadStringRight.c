#include<stdio.h>
#include<stdlib.h>

char* ReadUserName(){
	char * name = (char*)malloc(sizeof(char) * 30);
	printf("이름 : ");
	gets(name);
	//fgets(name, sizeof(name), stdin);
	return name;
}

int main(){
	char * name1;
	char * name2;
	
	name1 = ReadUserName();
	printf("What's your name? %s\n", name1);
	name2 = ReadUserName();
	printf("What's your name? %s\n", name2);
	
	printf("What's your name? %s\n", name1);
	printf("What's your name? %s\n", name2);
	
	
	// 5행에서 할당한 메모리 지우는 시점
	free(name1);
	free(name2);
	
	return 0;
}