#include<iostream>
#include<vector>
using namespace std;

class character {
	public:
	character() : hp(100), power(100) {};
	
	int get_hp() { return hp; };
	int get_power() { return power; };
	void set_hp(int _hp) { hp = _hp; };
	void set_power(int _power) { power = _power; };
	
	protected:
	int hp;
	int power;
};

class attack_ability { 
	public:
	enum class attack_type : int { forest = 0, urban, terrain, none = -1 };
	virtual void attack() {};
	
	protected:
	attack_type type = attack_type::none;
};

class forest_attack : public attack_ability {
	public:
	forest_attack() { type = attack_type::forest; };
	virtual void attack() final { cout << "수풀 속 공격" << endl; };
};

class urban_attack : public attack_ability {
	public:
	urban_attack(){ type = attack_type::urban; };
	virtual void attack() final {cout << "복잡한 도심 속 공격" << endl; };
};

class terrain_attack : public attack_ability {
	public :
	terrain_attack(){ type = attack_type::terrain; };
	virtual void attack() final { cout << "공격의 다양한 지현 활용" << endl; };
};

class dummy_attack : public attack_ability {
	public : 
	dummy_attack(){ type = attack_type::none; };
	virtual void attack() final {};
};

class monster : public character {
	public : 
	enum class monster_type {a,b,c} ;
	monster();
	virtual ~monster();
	void attack();
	monster* get_pointer(){return this;};
	monster_type get_type() {return type; };
	void set_alive(bool check) { alive = check; };
	void set_sacrifice(monster* target) { sacrifice = target; };
	
	protected :
	vector<attack_ability*> attack_methods;
	monster_type type = monster_type::a;
	monster* sacrifice = nullptr;
	bool alive = true;
	
	friend void merge (int multiplex, monster& mon, monster & target) {
		mon.set_hp(mon.get_hp() + multiplex * target.get_hp());
		mon.set_sacrifice(target.get_pointer());
		target.set_alive(false);
		switch(target.get_type()){
			case monster::monster_type::a :
				if(nullptr == mon.attack_methods[(int)monster::monster_type::a]){
					mon.attack_methods[(int)monster::monster_type::a] = new forest_attack;
				}
				break;
			case monster::monster_type::b:
				if(nullptr == mon.attack_methods[(int)monster::monster_type::b]){
					mon.attack_methods[(int)monster::monster_type::b] = new urban_attack;
				}
				break;
			case monster::monster_type::c:
				if(nullptr == mon.attack_methods[(int)monster::monster_type::c]){
					mon.attack_methods[(int)monster::monster_type::c] = new terrain_attack;
				}
				break;
		}
	};
};

class monster_a : public monster{
	public:
	monster_a(){
		type = monster_type :: a;
		attack_methods[(int)type] = new forest_attack;
	};
	monster_a& operator*(monster& target);
};

class monster_b : public monster{
	public:
	monster_b(){
		type = monster_type :: b;
		attack_methods[(int)type] = new urban_attack;
	};
	monster_b& operator*(monster& target);
};

class monster_c : public monster{
	public:
	monster_c(){
		type = monster_type :: c;
		attack_methods[(int)type] = new terrain_attack;
	};
	monster_c& operator*(monster& target);
};

monster_a& monster_a::operator*(monster& target){
	switch(target.get_type()){
		case monster_type::a:
			merge(2, *this, target);
			break;
		case monster_type::b:
			merge(3, *this, target);
			break;
		case monster_type::c:
			break;
	}
	return *this;
}

monster_b& monster_b::operator*(monster& target){
	switch(target.get_type()){
		case monster_type::a:
			merge(5, *this, target);
			break;
		case monster_type::b:
			merge(2, *this, target);
			break;
		case monster_type::c:
			break;
	}
	return *this;
}

monster_c& monster_c::operator*(monster& target){
	switch(target.get_type()){
		case monster_type::a:
			break;
		case monster_type::b:
			merge(4, *this, target);
			break;
		case monster_type::c:
			merge(2, *this, target);
			break;
	}
	return *this;
}

monster::monster(){
	for(int i=0; i<3; i++){
		attack_methods.push_back(nullptr);
	}
}

monster::~monster(){
	for(int i=0; i<3; i++){
		attack_ability *obj = attack_methods[i];
		
		if(nullptr != obj){
			delete obj;
			attack_methods[i] = nullptr;
		}
	}
}

void monster::attack(){
	for(auto && attack_method : attack_methods){
		if(nullptr == attack_method){
			continue;
		}
		attack_method -> attack();
	}
}

int main(){
	monster_a mon_a, mon_a2, mon_a3, sc_mon_a;
  	monster_b sc_mon_b;
  	monster_c sc_mon_c;

  	cout << "A : hp(" << mon_a.get_hp() << ")" << endl;
  	mon_a = mon_a * sc_mon_b;
  	cout << "A * B : hp(" << mon_a.get_hp() << ")" << endl;
  	mon_a.attack();
  	mon_a2 = mon_a2 * sc_mon_a;
  	cout << "A * A : hp(" << mon_a2.get_hp() << ")" << endl;
  	mon_a2.attack();
  	mon_a3 = mon_a3 * sc_mon_c;
  	cout << "A * C : hp(" << mon_a3.get_hp() << ")" << endl;
  	mon_a3.attack();

  	return 0;
}