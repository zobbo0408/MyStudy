#include<iostream>
#include<string>

using namespace std;

void check_found(string::size_type n) {
	if(n == string::npos){
		cout << "not found" << endl;
	}
	
	else {
		cout << "find index : " << n << endl;
	}
}

int main(){
	string::size_type n; // 문자열의 크기를 나타내는 부호없는 정수
	string str = "This is an example of a standard string.";
	
	// 문자열 시작 지점부터 "example" 탐색
	n = str.find("example");
	check_found(n);
	cout << n << endl;
	
	// 문자열 내 index 위치 4부터 "is" 탐색
	n = str.find("is", 4);
	check_found(n);
	
	// 문자열 시작 지점부터 'h' 탐색
 	n = str.find('h');
  	check_found(n);

  	// 문자열 시작 지점부터 'k' 탐색
  	n = str.find('k');
  	check_found(n);
	cout << n << endl;
	
	return 0;
}