#include<iostream>
#include<list>
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

class monster{
	public:
	monster(){};
	void attack(player target_player);
	virtual void attack_special(player target_player);
	virtual void attack_at_down() = 0; // 순수 가상 함수
};

void monster::attack_special(player target_player){
	cout << "기본 공격 : 데미지 - 10 hp" << endl;
}

class monster_a : public monster, character{
	public:
	virtual void attack_special(player target_player)override;
	virtual void attack_at_down() override;
};

void monster_a::attack_special(player target_player){
	cout << "인텡글 공격  : 데미지 - 15 hp" << endl;
}

void monster_a::attack_at_down(){
	cout << "동쪽에서 기습!" << endl;
}

class monster_b : public monster, character{
	public:
	virtual void attack_special(player target_player) override;
	virtual void attack_at_down() override;
};

void monster_b::attack_special(player target_player){
	cout << "가상 공격 : 데미지 - 0 hp" << endl;
}

void monster_b::attack_at_down(){
	cout << "적진에 조용히 침투하여 방화!" << endl;
}

class monster_c: public monster, character{
	public:
	virtual void attack_special(player target_player) override;
	virtual void attack_at_down() override;
};

void monster_c::attack_special(player target_player) {
	cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
}

void monster_c::attack_at_down(){
	cout << "남쪽에서 적진을 향해 대포 발사!" << endl;
}

int main(){
	list<monster*> mon_list;
	player player_1;
	
	monster_a first_monster;
	mon_list.push_back(&first_monster);
	
	monster_b second_monster;
	mon_list.push_back(&second_monster);
	
	monster_c third_monster;
	mon_list.push_back(&third_monster);
	
	for(auto item : mon_list){
		item -> attack_at_down();
		item -> attack_special(player_1);
		cout << endl;
	}
	
	return 0;
}