#include<iostream>
#include<cstdlib>

using namespace std;

void myterminate(){
	cout << "myerminate called" << endl;
	exit(-1); // 비정상 종료
}

int main(){
	set_terminate(myterminate);
	throw 1;
	
	return 0;
}