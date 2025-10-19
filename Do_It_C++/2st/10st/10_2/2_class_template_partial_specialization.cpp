#include<iostream>

using namespace std;

template<typename Type1, typename Type2>
class data_package {
public:
	data_package(Type1 first, Type2 second) : first(first), second(second) {};
	void print_out_element(){
		cout << "첫 번째 요소 : " << first << ", " << "두 번째 요소 : " << second << endl;
	};
	
private:
	Type1 first;
	Type2 second;
};

// 클래스 템플릿 부분 특수화 첫번째 인자가 string형인 경우!
template <typename T>
class data_package<string, T> {
public:
	data_package(string first, T second) : first(first), second(second) {};
	void print_out_element(){
		cout << first << "와 함께 입력된 " << second << endl;
	};
	
private:
	string first;
	T second;
};

int main(){
	// data_package template_inst1(10, 10.5); -> 오류!! c++14부터 오류!
	data_package<int, double> template_inst1(5, 10.5);
	data_package<string, int> template_inst2("문자열", 5);
	
	template_inst1.print_out_element();
	template_inst2.print_out_element();
}