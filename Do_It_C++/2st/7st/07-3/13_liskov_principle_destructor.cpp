#include<iostream>

using namespace std;

class monster {
	public:
	monster(){
		cout << "monster 생성자" << endl;
	};
	~monster(){
		cout << "monster 소멸자" << endl;
	};
};

class monster_a : public monster{
	public:
	monster_a(){
		cout << "monster_a 생성자" << endl;
	};
	~monster_a(){
		cout << "monster_a 소멸자" << endl;
	};
};

int main(){
	monster * forest_monster = new monster_a(); 
	// 부모 클래스의 포인터를 자식 클래스의 객체로 대입
	delete forest_monster;
	return 0;
}