// 스템 호출(system call) 직접 관찰하기, strace 사용해보기.
// 설치 : apt-get install strace
// system call : 사용자가 실행한 프로세스가 하드웨어(cpu, memory, 통신  ,I/O 등등의 많은 자원!)에 접근해야할 때
// 				 kernel에 자원 쓰게해주세요! 라고 하는 것들을 system call 이라고 부른다
// strace 명령어를 찾아보면 시스템 콜,시그널을 추적하는 디버깅 툴
// 사용 법 : strace <<명령어>>
// 시스템 콜만 추적하는 법 : strace -e write <<명령어>>

#include<stdio.h>

int main() {
	printf("Hello, Hongong!\n");
	
	return 0;
}