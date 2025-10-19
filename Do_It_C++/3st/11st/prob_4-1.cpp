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
	int num;
	
	cout << " 주사위를 몇 번 던지시겠습니까?";
	cin >> num;
	
	for (int i = 0; i < num; ++i) {
    	int dice1 = mt_rand() % 6 + 1;
    	int dice2 = mt_rand() % 6 + 1;
    	int sum = dice1 + dice2;
    	cout << "주사위 " << i + 1 << "번째 던지기 결과: " << dice1 << " + " << dice2 << " = " << sum << endl;
    }
	
	return 0;
}