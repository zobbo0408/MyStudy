#include<iostream>
#include<string>

using namespace std;

void compare_result(int result) {
	if(result == 0) {
		cout << result << " = 두 문자열이 같음" << endl;
	}
	else if(result > 0) {
		cout << result << " = 대상 문자열이 더 길거나 일치하지 않는 첫 번째 문자가 더 큼" << endl;
	}
	else {
		cout << result << " = 대상 문자열이 더 짧거나 일치하지 않는 첫 번째 문자가 더 작음" << endl;
	}
}

int main(){
	// 두 문자열이 일치할 때
	string s1 = "Hello";
	string s2 = "Hello";
	int result = s1.compare(s2);
	compare_result(result);
	
	// s1이 더 짧을 때
	s1 = "Hello";
	s2 = "Hello, World";
	result = s1.compare(s2);
	compare_result(result);
	
	// 두 문자열의 길이가 같고, s1의 알파벳이 먼저 나올 때
	s1 = "cat";
	s2 = "dog";
	result = s1.compare(s2);
	compare_result(result);
	
	// s1이 더 길 때
	s1 = "Hello, World";
	s2 = "Hello";
	result = s1.compare(s2);
	compare_result(result);
	
	// s1이 더 짧지만, 알파벳이 더 빨리 나올 때 
	// 우선 순위는 알파벳의 순서가 더 작은 것이 중요하다.
	s1 = "cat";
	s2 = "apple";
	result = s1.compare(s2);
	compare_result(result);
	
	return 0;
}