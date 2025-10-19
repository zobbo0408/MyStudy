#include<iostream>
#include<string>			// 반환자를 string으로 쓰기 위한 헤더
#include<cstring>			// 스트링 함수를 사용하기 위한 헤더
using namespace std;

class character {
	public:
	character() : hp(100), power(100){	};
	void get_damage(int _damage){};
	
	protected:
	int hp;
	int power;
};

class player : public character{
	public:
	player(){};
};

class monster{
	public:
	void attack(player target_player){};
	virtual void attack_special(player target_player);
};

void monster :: attack_special(player target_player){
	cout << "기본공격 : 데미지 - 10 hp" << endl;
}

class monster_b : public monster, character{
	public:
	monster_b(player& attack_target):
	monster_type("일반"),				// 직접 초기화
	location{0, 0},						// 유니폼 초기화
	unique_id(++total_count),			// 상수 변수 초기화 (무조건 초기화 목록에)
	target(attack_target){				// 클래스 레퍼런스 변수 초기화 (무조건 초기화 목록에)
		difficult_level = 10;			// 복사초기화 (대입 연산 초기화), 본문에서 초기화 (대입)
		quiz = new char[1024];			// 동적 메모리 할당, 본문에서 초기화 (대입)
	};
	
	~monster_b(){
		delete[] quiz;
		total_count -- ;
	};
	
	monster_b(const monster_b &ref); // 복사 생성자 선언
	
	void set_quiz(const char* new_quiz) {strcpy(quiz, new_quiz);};
	void set_type(string type){monster_type = type;};
	void set_difficult_level(int level){difficult_level = level;};
	void set_location(int x, int y){location[0] = x; location[1] = y;};
	char * get_quiz(){return quiz;};
	string get_type(){return monster_type;};
	int get_difficult_level(){return difficult_level;};
	int get_x_location(){return location[0];};
	int get_y_location(){return location[1];};
	
	private:
	const int unique_id = 0;
	player& target;
	static int total_count;
	char* quiz;
	int difficult_level;
	int location[2];
	string monster_type;
};

int monster_b::total_count = 0; // 정적 멤버 변수 초기화는 전역 범위에서!

monster_b::monster_b(const monster_b &ref) : unique_id(++total_count), target(ref.target){
	quiz = new char[1024];
	strcpy(quiz, ref.quiz);
	monster_type = ref.monster_type;
	difficult_level = ref.difficult_level;
    location[0] = ref.location[0];
    location[1] = ref.location[1];
}

int main() {
  player first_player;
  monster_b first_mon(first_player);
  first_mon.set_quiz("아침에 네발, 점심에는 두발, 저녁에는 두발인 것은?");
  first_mon.set_difficult_level(100);
  first_mon.set_type("수수께끼 몬스터");
  first_mon.set_location(30, 30);

  monster_b second_mon = first_mon;
  second_mon.set_quiz("문이 뒤집어 지면 무엇이 될까?");
  second_mon.set_location(45, 50);

  cout << "[" << first_mon.get_x_location() << " , " << first_mon.get_y_location()
    << "] 첫번째 몬스터(" << first_mon.get_type() << " - "
    << first_mon.get_difficult_level()
    << ")가 내는 수수께끼 : " << first_mon.get_quiz() << endl;
  cout << "[" << second_mon.get_x_location() << " , " << second_mon.get_y_location()
    << "] 두번째 몬스터(" << second_mon.get_type() << " - "
    << second_mon.get_difficult_level()
    << ")가 내는 수수께끼 : " << second_mon.get_quiz() << endl;

  return 0;
}