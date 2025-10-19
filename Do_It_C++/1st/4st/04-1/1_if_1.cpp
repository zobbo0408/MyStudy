#include<iostream>
using namespace std;

int main(){
	int input_data;
	
	cout << "정수 입력 : ";
	cin >> input_data;
	
	if(input_data > 0){
		cout << "입력한 수는 양수 입니다." << endl;
	}
	else if(input_data < 0){
		cout << "입력한 수는 음수 입니다." << endl;
	}
	else{
		cout << "입력한 수는 0입니다." << endl;
	}
	
	return 0;
}