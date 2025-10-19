#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_LOOP 100000

int num = 0;
sem_t sem;

void* foo (void* arg) {
	sem_wait(&sem); // 세마포어 획득
	
	for (int i=0; i<NUM_LOOP; i++) {
		num++;
	}
	
	sem_post(&sem); // 세마포어 반환
	return NULL;
}

int main() {
	pthread_t t1, t2;
	
	sem_init(&sem, 0, 1); // 초기값 1인 세마포어 초기화
	
	pthread_create(&t1, NULL, foo, NULL);
	pthread_create(&t2, NULL, foo, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	printf("final num : %d\n", num);
	
	sem_destroy(&sem); // 세마포어 제거
	
	return 0;
}

// c++20 버전 (std::counting_semaphore)

// #include <iostream>
// #include <thread>
// #include <semaphore>

// const int NUM_LOOP = 100000;
// int num = 0;
// std::counting_semaphore<1> sem(1); // 세마포어 초기값 1

// void foo() {
// 	sem.acquire(); // 세마포어 획득
	
// 	for(int i=0; i<NUM_LOOP; i++) {
// 		num++;
// 	}
	
// 	sem.release(); // 세마포어 반환
// }


// int main() {
// 	std::thread t1(foo);
// 	std::thread t2(foo);
	
// 	t1.join();
// 	t2.join();
	
// 	std::cout << "Final num : " << num << std::endl;
	
// 	return 0;
// }