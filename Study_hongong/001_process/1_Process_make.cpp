#include <stdio.h>
#include <unistd.h> // getpid() 함수 사용을 위한 라이브러리

int main() {
	printf("hello, os\n");
	printf("my pid is %d\n", getpid());
	// 여러 번 반복적으로 실행했을 때 다른 PID 값이 출력될 수 있다.
	
	return 0;
}