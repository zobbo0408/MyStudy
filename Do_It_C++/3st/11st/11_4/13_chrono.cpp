#include<iostream>
#include <chrono>
#include <random>

using namespace std;

int main(){
	// 시드값 적용
	auto curTime = chrono::system_clock::now();
	auto duration = curTime.time_since_epoch();
	auto millis = chrono::duration_cast<chrono::milliseconds>(duration).count();
	
	mt19937_64 mt_rand(millis);
	
	for(int i=0; i<10; i++) {
		cout << mt_rand() << endl;
	}
}