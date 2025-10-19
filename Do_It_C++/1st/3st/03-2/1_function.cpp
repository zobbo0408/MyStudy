#include<iostream>
using namespace std;

int add(int _x, int _y){
	int _result = _x + _y;
	return _result;
}

int main(){
	int add_result = add(2,3);
	cout << "add 함수 결과 : " << add_result << endl;
	
	return 0;
}