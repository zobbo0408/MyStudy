#include<iostream>
#include<string>

using namespace std;

int main(){
	string str1("");
	cout << str1 << endl;
	
	cout << std::boolalpha; // 1(true) 값을 true, 0(false) 값을 false로 출력한다.
	cout << str1.empty() << endl; // true or false (원래는 1 or 0)
	
	return 0;
}