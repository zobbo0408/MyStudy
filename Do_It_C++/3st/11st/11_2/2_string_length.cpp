#include<iostream>
#include<string>

using namespace std;

int main(){
	string str1("Hello");
	cout << str1 << endl;
	
	cout << str1.length() << endl; // 문자열의 길이 반환
	cout << str1.size() << endl;   // 객체가 차지하는 메모리의 크기 반환
	// c++에서 string은 널 문자를 가지지 않기에, length 함수와 size 함수가 같다.
	
	return 0;
}