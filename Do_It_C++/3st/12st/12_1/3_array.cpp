#include <iostream>
#include <array>
using namespace std;

int main(){
	array <int, 5> myArray;
	
	myArray = {1, 2, 3, 4, 5};
	cout << "배열 출력 : ";
	for(int i=0; i<5; i++){
		cout << myArray[i] << " ";
	}
	cout << endl;
	
	// 배열 크기 출력
	cout << "배열 크기 : "<< myArray.size() << endl;
	
	myArray[2] = 10;
	
	cout << "달라진 배열 출력 : ";
	for(int i=0; i<5; i++){
		cout << myArray[i] << " ";
	}
	cout << endl;
}