/*
문제 1 함수 템플릿 #1
템플릿을 사용해 다양한 데이터 형식의 값을 출력하는 함수를 만들어 보세요. 
print_data(T data) 형식으로 함수 템플릿을 만들어서 cout으로 “입력받은 값은 :”이라는 문장과 함께 입력받은 값을 출력하는 함수를 만들어 보세요.
*/

#include<iostream>

using namespace std;

template <typename T>
void print_data(T data) {
	cout << "입력받은 값은 : " << data << endl;
}

int main(){
	print_data(5);
	
	return 0;
}