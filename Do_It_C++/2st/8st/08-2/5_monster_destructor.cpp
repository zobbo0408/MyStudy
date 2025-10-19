// 소멸자를 가상함수로 선언하지 않으면, 업캐스팅이 발생했을 때 자식 클래스 
// 소멸자가 호출되지 않으며, 아래 코드에선 메모리 누수도 발생함.

#include<iostream>

using namespace std;

class monster{
	public:
	monster();
	virtual ~monster();
	
	private:
	int *dummy;
};

monster::monster(){
	cout << "monster 생성자 호출" << endl;
	dummy = new int;
}

monster::~monster(){
	cout << "~monster 소멸자 호출" << endl;
	delete dummy;
}

class monster_a : public monster{
	public:
	monster_a();
	~monster_a();
	
	private:
	int* dummy_a;
};

monster_a::monster_a(){
	cout << "monster_a 생성자 호출" << endl;
	dummy_a = new int;
}

monster_a::~monster_a(){
	cout << "~monster_a 소멸자 호출" << endl;
	delete dummy_a;
}

int main(){
	monster* mon = new monster_a(); // 업캐스팅 발생
	
	delete mon;
	
	return 0;
}