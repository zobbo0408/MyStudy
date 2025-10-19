#include<iostream>
using namespace std;

int getID(){
	static int ID = 0;
	return ++ID;
}

int main(){
	cout << "ID : " << getID() << endl;
	cout << "ID : " << getID() << endl;
	cout << "ID : " << getID() << endl;
	cout << "ID : " << getID() << endl;
	cout << "ID : " << getID() << endl;
	
	return 0;
}