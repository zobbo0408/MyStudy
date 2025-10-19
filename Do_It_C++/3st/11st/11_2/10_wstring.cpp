#include<iostream>
#include<string>
using namespace std;

int main(){
	/*
	유니코드는 모든 문자를 표현하기 위한 '표준 문자 시스템'이며,
	c++에서는 wstring을 통해 유니코드 문자열 사용가능*/
	
	// setlocale 함수를 사용하여 프로그램의 로케일(locale)을 변경
	// LC_ALL은 '모든 로케일' 설정으로 지정을 의미함
	setlocale(LC_ALL, ""); // 지역 설정
	
	// wstring을 사용하여 유니코드 문자열을 초기화
	// L 접두사를 붙여 유니코드 문자열임을 나타냄
	wstring korString = L"안녕하세요";
	
	// wcout을 사용하여 유니코드 문자열을 출력
	// wcout은 유니코드 문자열을 출력하기 위한 wide character 출력 스트림
	wcout << korString << endl;
	
	return 0;
}