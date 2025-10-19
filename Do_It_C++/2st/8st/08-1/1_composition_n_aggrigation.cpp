#include<iostream>

using namespace std;

// 캐릭터의 속성을 가지고 있는 캐릭터 클래스
class character{
	public:
	character() : hp(100), power(100){};
	int get_hp(){return hp;};
	int get_power(){return power;};
	
	protected:
	int hp;
	int power;
};

//character 클래스를 상속받은 player 클래스
class player{
	public:
	player(){};
	
	private:
	character main_body; // 컴포지션 활용
};

// monster 클래스
class monster{
	public:
	monster(){};
	void get_damage(int _damage){};
	virtual void attack(player target_player){
		cout << "공격 : 데미지 - 10 hp" << endl;
	};
};

class monster_2nd_gen : public monster{
	public:
	virtual void attack(player target_player) override{
		cout << "새로운 공격 : 데미지 - 30 hp" << endl;
	};
};

// 몬스터 A는 monster, character 클래스를 컴포지션으로 포함
class monster_a {
	public: 
	void attack(player target_player){
		main_role.attack(target_player);
	};
	
	private:
	character main_body;
	monster main_role;
};

// 몬스터 B는 monster, character 클래스를 어그리게이션으로 포함
class monster_b{
	public:
	monster_b (character& ref_character, monster& ref_monster) : 
		main_body(ref_character), main_role(ref_monster){};
	void attack (player target_player){
		main_role.attack(target_player);
	};
	
	private:
	character& main_body;
	monster& main_role;
};

int main(){
	player player1;
	character character_obj;
	monster monster_obj;
	monster_2nd_gen monster_new_obj;
	
	// 내부에서 객체를 생성하는 컴포지션
	monster_a forest_monster;
	
	// 외부에서 객체를 생성하는 어그리게이션
	monster_b tutorial_monster(character_obj, monster_obj);
	monster_b urban_monster(character_obj, monster_new_obj);
	
	cout << "몬스터 A 공격" << endl;
	forest_monster.attack(player1);
	
	cout << endl << "몬스터 B 공격" << endl;
	tutorial_monster.attack(player1);
	urban_monster.attack(player1);
	
	return 0;
}