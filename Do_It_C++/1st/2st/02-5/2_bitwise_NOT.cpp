//비트 연산자로 1의 보수 구하기
#include<iostream>
using namespace std;

int main(){
	unsigned int value = 0x00000000;
	
	value = ~value;
	cout << value << endl;
	
	return 0;
}