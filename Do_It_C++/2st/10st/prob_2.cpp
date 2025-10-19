/*
템플릿을 이용해서 is_equal(T data1, T data2) 함수를 만들어 보세요. 이 함수 템플릿은 다음과 같은 규칙으로 data1, data2가 같은 값임을 판단합니다.
이외의 데이터 형식은 false를 반환합니다. is_equal 함수를 호출할 때 data1, data2에는 같은 데이터 형식의 값을 입력한다고 가정합니다.

데이터 형식	같읕 값 판단 기준
bool	data1과 data2의 논릿값이 true나 false로 같을 때
int	data1 == data2 연산이 참일 때
float	data1 - data2 연산의 절댓값이 0.000001 이하일 때
double
string	영문으로만 국한해서 빈칸과 문장 부호는 무시하고 대·소문자 구별 없이 문장 안에 모든 알파벳의 개수와 순서가 같을 때
*/

#include<iostream>
#include<cctype>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

const double num = 1e-6; // 0.000001

template <typename T>
bool is_equal(T data1, T data2) {
	return (data1 == data2) ? true : false;
}

template <>
bool is_equal(bool data1, bool data2) {
	switch(data1) {
		case true:
			if(data2 == true){
				return true;
			}
			else{
				return false;
			}
			break;
			
		case false:
			if(data2 == true) {
				return false;
			}
			else{
				return true;
			}
			break;
	}
}

template <>
bool is_equal(int data1, int data2) {
	if(data1 == data2){
		return true;
	}
	
	return false;
}

template <>
bool is_equal(float data1, float data2) {
	if(abs(data1 - data2) <= num){
		return true;
	}
	
	return false;
}

template <>
bool is_equal(double data1, double data2) {
	if(abs(data1 - data2) <= num){
		return true;
	}
	
	return false;
}

template <>
bool is_equal(string data1, string data2) {
	data1.erase(remove_if(data1.begin(), data1.end(), ::isspace), data1.end()); // 공백 제거
	data2.erase(remove_if(data2.begin(), data2.end(), ::isspace), data2.end()); // 공백 제거
	
	std::transform(data1.begin(), data1.end(), data1.begin(), tolower);
	std::transform(data2.begin(), data2.end(), data2.begin(), tolower);

  	return data1 == data2 ? true : false;
}

int main(){
  bool bool1 = true, bool2 = false;
  int int1 = 33, int2 = 33;
  float float1 = 2.3456987f, float2 = 2.3456983f;
  double double1 = 342.345697, double2 = 342.345695;
  string string1 = "Hello, World\tand new world",
    string2 = "Hello,World and New world";

  cout << "bool 비교: " << boolalpha << bool1 << " vs " << bool2 << " is - " << is_equal(bool1, bool2) << endl;
  cout << "int 비교: " << int1 << " vs " << int2 << " is - " << is_equal(int1, int2) << endl;
  cout.precision(8);
  cout << "float 비교: " << float1 << " vs " << float2 << " is - " << is_equal(float1, float2) << endl;
  cout.precision(9);
  cout << "double 비교: " << double1 << " vs " << double2 << " is - " << is_equal(double1, double2) << endl;
  cout << "string 비교: '" << string1 << "' vs '" << string2 << "' is - " << is_equal(string1, string2) << endl;


  return 0;
}