#include<iostream>
using namespace std;

void swap(int a, int b){
	cout << "[swap func] before swap, a : " << a << ", " << "b : " << b << endl;
	
	int temp = a;
	a = b;
	b = temp;
	
	cout << "[swap func] after swap, a : " << a << ", " << "b : " << b << endl << endl;
}

int main(){
	int a = 5, b = 10;
	
	cout << "[main func] before swap, a : " << a << ", " << "b : " << b << endl << endl;
	
	swap(a, b);
	
	cout << "[main func] after swap, a : " << a << ", " << "b : " << b << endl;
	
	return 0;
}