#include<iostream>
#include<string>
using namespace std;

class character {
	public:
	character(): hp(100), power(100), location { 0, 0 }, level(1){};
	void move(int x, int y){};
	void move(int x, int y, int spot_count){};
	void get_damage(int _damage){};
	int get_hp(){return hp;};
	int get_level(){return level;};
	void set_level(int level_value){ level = level_value; };
	void set_hp(int _hp){hp = _hp;};
	
	protected:
	int hp, power, level, location[2];
};

class player : public character {
	public:
	player(){};
};

class monster {
	public:
	void attack(player target_player){};
	virtual void attack_special(player target_player);
};

void monster::attack_special(player target_player){
	cout << "기본 공격 : 데미지 - 10 hp" << endl;
}

class monster_c : public monster {
	public:
	virtual void attack_special(player target_player) override;
	void set_body(character* object){ body = object; }; // body는 character 객체
	monster_c operator+(monster_c& operand);
	monster_c operator+(player& operand);
	void set_level(int level_value){ (*body).set_level(level_value); };
	void set_hp(int _hp){ body->set_hp(_hp); };
	int get_level(){return body->get_level(); };
	int get_hp(){ return body->get_hp(); };
	
	private:
	character* body = nullptr;
	character* return_body() {return body;}
};

monster_c monster_c::operator+(monster_c& operand){
	monster_c result_monster;
	result_monster.set_body(body);
	result_monster.set_level(body->get_level() + operand.get_level());
	return result_monster;
}

monster_c monster_c::operator+(player& operand){
	monster_c result_monster;
	result_monster.set_body(body);
	result_monster.set_hp(body->get_hp() + operand.get_hp());
	return result_monster;
}

void monster_c::attack_special(player target_player){
	cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
}

int main(){
	player player_1;
	monster_c monster_c_obj_1, monster_c_obj_2;
	character body_1, body_2;
	
	monster_c_obj_1.set_body(&body_1);
	monster_c_obj_2.set_body(&body_2);
	monster_c_obj_2.set_level(2);
	
	monster_c monster_new_obj = monster_c_obj_1 + monster_c_obj_2;
	
	cout << "Player 합체 전 몬스터C HP[" << monster_new_obj.get_hp()
    << "]" << endl;
	
	monster_new_obj = monster_new_obj + player_1;
	
	cout << "Player 합체 후 몬스터C HP[" << monster_new_obj.get_hp()
    << "]" << endl;

 	return 0;
	
}