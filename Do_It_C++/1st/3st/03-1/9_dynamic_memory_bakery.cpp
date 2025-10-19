#include<iostream>
//#include<string>
using namespace std;

int main(){
	int customer_num = 0;
	
	cout << "Today customer's num : ";
	cin >> customer_num;
	
	string *bread = new string[customer_num];
	
	for(int i=0; i<customer_num; i++){
		*(bread + i) = "Bread_" + to_string(i+1);
	}
	
	cout << endl;
	cout << "오늘 생산된 빵" << endl;
	
	for (int i=0; i<customer_num; i++){
		cout << *(bread + i) << endl;
	}
	
	delete[] bread;
	
	return 0;
}