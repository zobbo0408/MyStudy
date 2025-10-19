#include<iostream>
#include<string>

using namespace std;

int main(){
	string s1 = "Hello";
	string s2 = "Hello";
	
	if(s1 == s2) {
		cout << "두 문자열이 일치" << endl;
	}
	
	s2 = "World";
	if(s1 != s2) {
		cout << "두 문자열이 불일치" << endl;
	}
	
	return 0;
}