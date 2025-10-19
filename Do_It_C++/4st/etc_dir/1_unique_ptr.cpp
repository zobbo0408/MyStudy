#include <iostream>
#include <memory> // 스마트 포인터를 사용하기 위한 헤더

using namespace std;

class class_object {
	public :
	class_object() {
		cout << "메모리가 할당되었습니다." << endl;
	};
	~class_object() {
		cout << "메모리가 해제되었습니다." << endl;
	};
	
	void print_out() {
		cout << "객체의 함수를 호출합니다." << endl;
	};
};

int main() {
	// 메모리 누수 코드
	// class_object *unique_pointer = new class_object();
	// return 0;
	
	unique_ptr<class_object> unique_pointer(new class_object());
	unique_pointer->print_out();
	return 0; // 따로 메모리 해제 안함.
}