#include <stdio.h>
#include <unistd.h>

int main() {
	printf("parent pid is %d\n", getpid());
	
	// fork()를 통해 자식 프로세스 생성
	// fork()는 자식프로세스를 생성하고, fork()의 결과로 반환되는 값이 0인 
	// 프로세스는 자식 프로세스, 반환되는 값이 자식 프로세스의 PID인 프로세스는
	// 부모 프로세스이다.
	if(fork() == 0) { 
		// fork의 결과가 0일 경우 해당 프로세스를 자식 프로세스로 간주할 수 있는 것
		printf("child pid is %d\n", getpid());
	}
	// 예시에서 중요한 점은 fork가 된 순간
	// 동일한 코드를 실행하는 자식 프로세스가 생성되었다는 점
	printf("executed!\n"); // 2번 실행
	
	return 0;
}