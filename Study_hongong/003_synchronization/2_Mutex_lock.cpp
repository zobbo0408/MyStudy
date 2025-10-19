// #include <stdio.h>
// #include <pthread.h>

// #define NUM_THREAD 4
// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// int shared = 0;

// void *foo (void* arg) {
	
// 	pthread_mutex_lock(&mutex);
	
// 	// 이 부분은 임계구역
// 	for (int i=0; i< 10000; ++i) {
// 		shared += 1;
// 	}
	
// 	pthread_mutex_unlock(&mutex);
	
// 	return NULL;
// }

// int main() {
// 	pthread_t threads[NUM_THREAD];
	
// 	for (int i=0; i<NUM_THREAD; ++i) {
// 		pthread_create(&threads[i], NULL, foo, NULL);
// 	}
	
// 	for (int i=0; i<NUM_THREAD; ++i) {
// 		pthread_join(threads[i], NULL);
// 	}
	
// 	printf ("final result is %d\n", shared);
	
// 	return 0;
// }

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

const int NUM_THREAD = 4;

int shared = 0;
std::mutex mtx;

void foo() {
	std::lock_guard<std::mutex> lock(mtx);  // 자동으로 lock/unlock 관리
	
	// 임계구역
	for (int i = 0; i < 10000; ++i) {
        shared += 1;
    }
}

int main() {
	std::vector<std::thread> threads;
	
	for (int i=0; i<NUM_THREAD; ++i) {
		threads.emplace_back(foo); // 스레드 생성 및 함수 실행
	}
	
	for (auto& t : threads) {
		t.join(); // 스레드 종료 대기
	}
	
	std::cout << "final result is " << shared << std::endl;
	
	return 0;
}