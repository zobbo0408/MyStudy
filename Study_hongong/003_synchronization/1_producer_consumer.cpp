#include <iostream>
#include <queue>
#include <thread>

// using namespace std;

void produce();
void consume();

// std::queue<int> q;
int sum = 0;

int main() {
	std::cout << "초기 합계 : " << sum << std::endl;
	std::thread producer(produce);		// produce 라는 함수를 10만번 실행하는 producer 스레드
	std::thread consumer(consume);		// consume 이라는 함수를 10만번 실행하는 consumer 스레드
	
	producer.join();
	consumer.join();
	
	std::cout << "producer, consumer 스레드 실행 이후 합계 : " << sum << std::endl;
	
	return 0;
}

void produce() {
	for (int i=0; i<100000; i++){
		// q.push(1);
		sum ++;
	}
}

void consume() {
	for (int i=0; i<100000; i++) {
		sum --;
	}
}