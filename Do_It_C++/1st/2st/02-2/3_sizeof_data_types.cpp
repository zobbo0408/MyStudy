// 정수형 크기 출력하기
#include <iostream>
using namespace std;

int main(){
	cout << "short : " << sizeof(short) << "bytes" << endl;
	cout << "unsigned short : " << sizeof(unsigned short) << "bytes" << endl;
	cout << "int : " << sizeof(int) << "bytes" << endl;
	cout << "unsigned int : " << sizeof(unsigned int) << "bytes" << endl;
	cout << "long : " << sizeof(long) << "bytes" << endl;
	cout << "unsigned long : " << sizeof(unsigned long) << "bytes" << endl;
	cout << "long long : " << sizeof(long long) << "bytes" << endl;
	cout << "unsigned long long : " << sizeof(unsigned long long) << "bytes" << endl;
}