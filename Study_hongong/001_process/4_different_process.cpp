/*
프로그램이 워드 프로세서 프로그램이었다고 가정. 
그리고 foo 함수를 사용자로부터 입력받는 기능, 
bar 함수를 사용자가 입력한 값을 화면에 출력하는 기능, 
baz 함수를 사용자가 입력한 값의 맞춤법을 검사하는 기능이었다고 가정해 보세요. 
프로세스를 이해하고 능수능란하게 다룰 수 있다면 
각기 다른 작업을 동시에 수행하는 소스 코드를 작성할 수 있다.
*/
#include <stdio.h>
#include <unistd.h>

void foo() {
	printf("execute foo\n");
}

void bar() {
	printf("execute bar\n");
}

void baz() {
	printf("execute baz\n");
}

int main() {
	if(fork() == 0) {
		if(fork() == 0) {
			foo();
		}
		else{
			bar();
		}
	}
	
	else{
		baz();
	}
	
	return 0;
}