#include<iostream>
#include<list>

using namespace std;

class character {
	public:
	character() : hp(100), power(100){};
	
	private:
	int hp, power;
};

class player : public character {
	public:
	player(){};
};

class monster {
	public:
	monster();
	virtual ~monster();
	virtual void find_route() = 0;
	virtual void attack_special(player target_player) = 0;
};

monster::monster(){
	cout << "monster 부모 클래스 생성자 호출" << endl;
}

monster::~monster(){
	cout << "monster 부모 클래스 소멸자 호출" << endl;
}

class monster_a : public monster {
	public:
	virtual void find_route() override;
	virtual void attack_special(player target_player) override;
};

void monster_a::find_route(){
	cout << "깊이 우선 탐색 (DFS)" << endl;
}

void monster_a::attack_special(player target_player){
	cout << "인텡글 공격 : 데미지 - 15hp" << endl;
}

class monster_b : public monster {
	public:
	virtual void find_route() override;
	virtual void attack_special(player target_player) override;
};

void monster_b::find_route(){
	cout << "너비 우선 탐색 (BFS)" << endl;
}

void monster_b::attack_special(player target_player){
	cout << "가상 공격 : 데미지 - 0hp" << endl;
}

class monster_c : public monster {
	public:
	virtual void find_route() override;
	virtual void attack_special(player target_player) override;
};

void monster_c::find_route(){
	cout << "다익스트라 최단 경로 알고리즘" << endl;
}

void monster_c::attack_special(player target_player){
	cout << "강력 뇌전 공격 : 데미지 - 100hp" << endl;
}

void monster_routine(monster* mon, player target_player){
	mon -> find_route();
	mon -> attack_special(target_player);
}

int main(){
	list<monster*> mon_list;
	monster_a first_mon;
	monster_b second_mon;
	monster_c third_mon;
	player player_1;
	
	mon_list.push_back(&first_mon);
	mon_list.push_back(&second_mon);
	mon_list.push_back(&third_mon);
	
	for(auto item : mon_list){
		monster_routine(item, player_1);
		cout << endl;
	}
	
	return 0;
}