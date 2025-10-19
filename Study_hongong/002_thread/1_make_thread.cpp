/*
GCC로 pthread를 사용하는 프로그램을 컴파일할 때는 
반드시 -lpthread 또는 -pthread 옵션을 추가해야 합니다.
gcc -o 1_make_thread 1_make_thread.cpp -pthread
gcc -o 1_make_thread 1_make_thread.cpp -lpthread

-lpthread: libpthread.so 라이브러리를 명시적으로 링크
-pthread: 컴파일과 링킹 모두에 pthread 관련 플래그를 자동으로 설정*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* foo(void* arg) {
	printf("process id is %d\n", getpid());
	return NULL;
}

int main() {
	// thread 만들기
	pthread_t thread1;
	
	/*위 코드에서 foo()는 함수 포인터가 아니라 함수 호출 결과입니다. 
	pthread_create는 세 번째 인자로 함수 포인터를 받아야 합니다. 
	그런데 foo()라고 작성하면, foo 함수를 즉시 호출한 후, 
	그 반환값(여기선 NULL)을 넘기게 됩니다. 
	그래서 pthread_create는 NULL을 함수 포인터로 받게 되고, 
	결국 세그멘테이션 오류(segmentation fault) 가 발생하게 됩니다.*/
	
	pthread_create(&thread1, NULL, foo, NULL);
	/*
	pthread_create
	새로운 스레드를 생성하고, 해당 스레드에서 특정 함수를 실행하게 합니다.
	함수 원형 : 
	int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine)(void *), void *arg);
				   
	thread	생성된 스레드의 ID를 저장할 변수 포인터
	attr	스레드의 속성(보통 NULL로 두면 기본 속성 사용)
	start_routine	새 스레드가 실행할 함수 포인터 (void*를 인자로 받고 void*를 반환)
	arg	start_routine 함수에 전달할 인자 (void* 타입)			   */
	
	pthread_join(thread1, NULL);
	/*
	pthread_join
	함수 원형
	int pthread_join(pthread_t thread, void **retval);
	
	thread	기다릴 스레드의 ID
	retval	스레드 함수가 반환한 값을 받을 포인터 (NULL이면 무시됨)
	*/

	return 0;
}