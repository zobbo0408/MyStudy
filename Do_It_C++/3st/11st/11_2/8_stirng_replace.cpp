#include<iostream>
#include<string>

using namespace std;

int main(){
	string str = "Hello, World!";
	cout << "Original string : " << str << endl;
	
	str.replace(7, 5, "C++"); // 7번째 인덱스 값부터 5개의 값(World)을 세번째 인자로 바꿔라
	cout << "Replaced string : " << str << endl;
	
	return 0;
}