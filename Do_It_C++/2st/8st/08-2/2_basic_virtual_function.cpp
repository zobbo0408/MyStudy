#include<iostream>
using namespace std;

class character{
	public:
	character(): hp(100), power(100){};
	
	protected:
	int hp;
	int power;
};

class player : public character{
	public:
	player(){};
};


// 부모 클래스로 업캐스팅 하여 오버라이딩 된 함수를 사용하려면
// 가상 함수 선언을 하여 오버라이딩 해야 함.
class monster{
	public:
	monster(){};
	void attack(player target_player){};
	virtual void attack_special(player target_player);
};

void monster::attack_special(player target_player){
	cout << "기본 공격 : 데미지 - 10 hp" << endl;
}

// character는 private으로 상속
class monster_a : public monster, character{
	public:
	virtual void attack_special(player target_player)override;
};

void monster_a::attack_special(player target_player){
	cout << "인텡글 공격  : 데미지 - 15 hp" << endl;
}

class monster_b : public monster, character{
	public:
	virtual void attack_special(player target_player) override;
};

void monster_b::attack_special(player target_player){
	cout << "가상 공격 : 데미지 - 0 hp" << endl;
}

class monster_c: public monster, character{
	public:
	virtual void attack_special(player target_player) override;
};

void monster_c::attack_special(player target_player) {
	cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
}

int main(){
	player player_1;
	monster_a forest_monster;
	
	monster& mon = forest_monster; // 업캐스팅
	monster_a& mon_a = forest_monster;
	
	cout << endl << "부모 클래스로 업캐스팅 후 공격" <<  endl;
	mon.attack_special(player_1);
	
	cout << endl << "자식 클래스로 공격" << endl;
	mon_a.attack_special(player_1);
	
	cout << endl << "범위 연산자로 공격" << endl;
	mon_a.monster::attack_special(player_1);
	
	return 0;
}