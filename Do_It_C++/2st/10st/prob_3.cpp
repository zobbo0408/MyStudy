/*
[문제 2]서 작성한 소스 코드를 활용해 클래스 템플릿을 만들어 보세요. 
is_equal 함수 대신 operator==를 오버로드해서 만들어 보기 바랍니다.
*/
#include<iostream>
#include<cmath>
#include<cctype>
#include<string>
#include<algorithm>

using namespace std;

const double criteria_num = 1e-6;

template <typename T>
class data_package {
	public:
	data_package(T data) : member(data) {};
	bool operator==(data_package& operand) {
		return member == operand.get_member() ? true : false;
	};
	T get_member() { return member; };
	
	private:
	T member;
};

template <>
class data_package<bool> {
	public:
	data_package(bool data) : member(data) {};
	bool operator==(data_package<bool> operand) {
		bool result_value = false;
		bool operand_value = operand.get_member();
		switch(member) {
			case true:
				if(true == operand_value) {
					result_value = true;
				}
				break;
			case false:
				if(false == operand_value) {
					result_value = true;
				}
				break;
		};
		return result_value;
	};
	bool get_member() {
		return member;
	};
	
	private:
	bool member;
};

template <>
class data_package<int> {
	public:
	data_package(int data) : member(data) {};
	bool operator==(data_package<int> operand){
		return (member == operand.get_member()) ? true : false;
	};
	int get_member() {
		return member;
	};
	
	private:
	int member;
};

template <>
class data_package<float> {
	public:
	data_package(float data) : member(data) {};
	bool operator==(data_package<float> operand) {
		return (abs(member - operand.get_member()) <= criteria_num) ? true : false;
	};
	float get_member() {
		return member;
	};
	
	private:
	float member;
};

template <>
class data_package<double> {
	public:
	data_package(double data) : member(data) {};
	bool operator==(data_package<double> operand) {
		return (abs(member - operand.get_member()) <= criteria_num) ? true : false;
	};
	double get_member() {
		return member;
	};
	
	private:
	double member;
};

template <>
class data_package<string> {
	public:
	data_package(string data) : member(data) {
		member.erase(remove_if(member.begin(), member.end(), ::isspace), member.end());
		std::transform(member.begin(), member.end(), member.begin(), tolower);
	};
	bool operator==(data_package<string> operand) {
		return member == get_member() ? true : false;
	};
	string get_member() {
		return member;
	};
	
	private:
	string member;
};

int main()
{
  data_package<bool> bool1(true), bool2(false);
  data_package<int> int1(33), int2(33);
  data_package<float> float1(2.3456987f), float2(2.3456983f);
  data_package<double> double1(342.345697), double2(342.345695);
  data_package<string> string1("Hello, World\tand new world"),
                       string2("Hello,World and New world");

  cout << "bool 비교: " << boolalpha << bool1.get_member() << " vs " << bool2.get_member() << " is - " << (bool1 == bool2) << endl;
  cout << "int 비교: " << int1.get_member() << " vs " << int2.get_member() << " is - " << (int1 == int2) << endl; // int1.operator==(int2);
  cout.precision(8);
  cout << "float 비교: " << float1.get_member() << " vs " << float2.get_member() << " is - " << (float1 == float2) << endl;
  cout.precision(9);
  cout << "double 비교: " << double1.get_member() << " vs " << double2.get_member() << " is - " << (double1 == double2) << endl;
  cout << "string 비교: '" << string1.get_member() << "' vs '" << string2.get_member() << "' is - " << (string1 == string2) << endl;

  return 0;
}