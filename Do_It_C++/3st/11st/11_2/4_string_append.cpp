#include<iostream>
#include<string>
using namespace std;

int main(){
	string str1("Hello");
	cout << str1 << endl;
	str1.append(", World!");
	cout << str1 << endl;
	
	string str2("Hello");
	str2.append(", World", 6, 1); // 6번째 인덱스 값에서 1개를 뒤에 붙여라.
	cout << str2 << endl;
	str2.append(", World", 0, 4);
	cout << str2 << endl;
	
	return 0;
}