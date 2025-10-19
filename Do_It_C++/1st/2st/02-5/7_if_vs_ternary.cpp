// 삼항 연산자 활용하기
#include<iostream>
using namespace std;

int main(){
	int a= 7;
	int b = 5;
	int result;
	
	result = a>b ? a : b;
	
	cout << result << endl;
	return 0;
}