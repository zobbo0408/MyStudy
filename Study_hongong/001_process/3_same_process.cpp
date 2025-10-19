// 모든 프로세스들이 execute foo 라는 문자열을 출력하는 
// 동일한 작업(foo 함수 실행)을 수행

#include <stdio.h>
#include <unistd.h>

void foo() {
	printf("execute foo\n");
}

int main() {
	if(fork() == 0) { 
		if(fork() == 0) { // 10줄에서 또 fork된 child 프로세스
			printf("child of child pid is %d\n", getpid());
			foo();
		}
	
		else {// 9줄에서 fork된 child 프로세스
			printf("child pid is %d\n", getpid());
			foo();
		}
	}
	
	else {
        if(fork() == 0) { // 22줄에서 fork된 child 프로세스
        	printf("child pid is %d\n", getpid());
        	foo();
        }
     	else {	// parent 프로세스
       		 printf("parent pid is %d\n", getpid());
      		 foo();
      	}
    }
	
	return 0;
}