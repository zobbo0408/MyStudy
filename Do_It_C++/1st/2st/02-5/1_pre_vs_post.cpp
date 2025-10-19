// 증가 연산자, 전위/후의 연산 비교하기
#include<iostream>
using namespace std;

int main(){
	int a=0; // a 최초값은 0
	int b=0; // b 최초값은 0
	
	int a_prefix = ++a;
	int b_postfix = b++;
	
	cout << "a = " << a << ", " << "a_prefix = " << a_prefix << endl;
	cout << "b = " << b << ", " << "b_postfix = " << b_postfix << endl;
	
	return 0;
}