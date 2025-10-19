/* 
SRP 원칙 (Single Responsible Principle)
클래스는 한가지 기능만 수행해야 하고, 한가지 이유로만 변경되어야 한다. 

OCP 원칙 (Open - Closed Principle)
확장에 열려있고, 수정에 닫혀있어야 한다.
- 동적 바인딩 (업캐스팅 & 가상 함수 등)을 이용한다.
*/

#include <iostream>
#include <list>
#include <random>
#include <cmath>

using namespace std;

const int forest_terrain = 0;
const int cyber_terrain = 1;
const int urban_terrain = 2;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 99);

class character {
	public:
	character() : hp(100), power(100), location_x(0), location_y(0) {};
	int get_hp() { return hp; };
	int get_power(){ return power; };
	int get_location(bool x) {return x? location_x : location_y; };
	void set_location(int x, int y) {location_x = x, location_y = y; };
	
	protected:
	int hp, power, location_x, location_y;
};

class player : public character {
	public:
	player(){};
};

class monster : public character {
	public:
	// 템플릿 패턴을 위한 순수 가상 함수 구현
	virtual void find_route(player& target_player) = 0;
	virtual bool attach_target(player* target_player) = 0;
	virtual void check_target(player& target_player) = 0;
	virtual void attack_special(player& target_player) = 0;
	virtual void set_location(int x, int y) { monster_body.set_location(x, y); };
	virtual ~monster(){};
	
	protected:
	int calculate_distance(player& target_player);
	character* target_player = nullptr;
	
	private:
	character monster_body;
};

int monster::calculate_distance(player& target_player){
	return (int)sqrt(pow(target_player.get_location(true) - monster_body.get_location(true), 2) +
		pow(target_player.get_location(false) - monster_body.get_location(false), 2));
}

// monster factory 각 몬스터의 정의는 다른 클래스에서 하고
// 객체 생성은 해당 클래스에서 하므로 팩토리 패턴이라 함
class monster_factory {
	public:
	static void create_monster(const int terrain_type, int count);
	static void destroy_monster();
	static monster* get_monster(int index);
	static int get_monster_count();
	static void initialize_monster();
	
	private:
	static monster* create_monster(const int terrain_type);
	static list<monster*> mon_list;
	static int mon_count;
};

list<monster*> monster_factory::mon_list = {};
int monster_factory::mon_count = 0;

// 몬스터 A는 추상 클래스 Monster 클래스로부터 상속
class monster_a : public monster {
	public:
	virtual void find_route(player& target_player) override;
	virtual bool attach_target(player* target_player) override;
	virtual void check_target(player& target_player) override;
	virtual void attack_special(player &target_player) override;
};

void monster_a::attack_special(player& target_player) {
	cout << "인텐글 공격 : 데미지 - 15 hp" << endl;
}

void monster_a::find_route(player& target_player){
	cout << "타겟 찾아 가기 - 최단 거리 우선" << endl;
}

bool monster_a::attach_target(player* target_player){
	if(calculate_distance(*target_player) < 30) {
		// this가 가리키는 target_player는 매개변수가 아닌 
		// 멤버변수 target_player를 가리키는 것
		// 따라서 여기선 포인터 멤버변수인 target_player에
		// 매개변수 target_player의 메모리 주소를 초기화 한 것!
		this -> target_player = target_player;
		cout << "뒤따라 가면서 플레이어 쫒아 가기" << endl;
		return true;
	}
	
	return false;
}

void monster_a::check_target(player& target_player){
	if(target_player.get_hp() < 40){
		attack_special(target_player);
		return;
	}
}

class monster_b : public monster {
	public:
	virtual void find_route(player& target_player) override;
	virtual bool attach_target(player* target_player) override;
	virtual void check_target(player& target_player) override;
	virtual void attack_special(player &target_player) override;
};

void monster_b::attack_special(player& target_player) {
	cout << "가상 공격 : 데미지 - 0 hp" << endl;
}

void monster_b::find_route(player& target_player){
	cout << "타겟 찾아 가기 - 최소 시간 우선" << endl;
}

bool monster_b::attach_target(player* target_player){
	if(calculate_distance(*target_player) > 30) {
		this -> target_player = target_player;
		cout << "위치 추적을 통해서 찾아 가기" << endl;
		return true;
	}
	
	return false;
}

void monster_b::check_target(player& target_player){
	if(target_player.get_hp() < 10){
		attack_special(target_player);
		return;
	}
}

class monster_c : public monster {
	public:
	virtual void find_route(player& target_player) override;
	virtual bool attach_target(player* target_player) override;
	virtual void check_target(player& target_player) override;
	virtual void attack_special(player &target_player) override;
};

void monster_c::attack_special(player& target_player) {
	cout << "강력 뇌전 공격 : 데미지 100 - hp" << endl;
}

void monster_c::find_route(player& target_player){
	cout << "타겟 찾아 가기 - 타겟 시선에 보이지 않도록" << endl;
}

bool monster_c::attach_target(player* target_player){
	this -> target_player = target_player;
	cout << "눈에 띄면 무조건 따라감" << endl;
	
	return true;
}

void monster_c::check_target(player& target_player){
	attack_special(target_player);
}

int monster_factory::get_monster_count() {
  return mon_count;
}

monster* monster_factory::get_monster(int index){
	monster* new_mon = nullptr;
	auto item = mon_list.begin(); // 순회자
	advance(item, index); // mon_list 리스트에 해당 index를 item이 순회함
	new_mon = *item; // 해당 객체를 초기화
	
	return new_mon;
}

void monster_factory::initialize_monster(){
	create_monster(forest_terrain, 2);
	create_monster(cyber_terrain, 3);
	create_monster(urban_terrain, 1);
}

monster* monster_factory::create_monster(const int terrain_type){
	monster* new_mon = nullptr;
	switch(terrain_type){
		case forest_terrain:
			new_mon = new monster_a();
			break;
		case cyber_terrain:
			new_mon = new monster_b();
			break;
		case urban_terrain:
			new_mon = new monster_c();
			break;
	}
	
	mon_list.push_back(new_mon);
	mon_count++;
	
	return new_mon;
}

void monster_factory::destroy_monster(){
	for(auto mon : mon_list) {
		delete mon;
	}
}

void monster_factory::create_monster(const int terrain_type, int count){
	monster* mon = nullptr;
	
	for(int i=0; i<count; ++i){
		mon = monster_factory::create_monster(terrain_type);
		mon->set_location(dis(gen), dis(gen));
	}
}

// 순수 가상 함수의 조합으로 흐름을 정의하는 전역 함수
void monster_routine(monster* mon, player target_player){		// 업캐스팅(동적 바인딩)
	mon->attach_target(&target_player);
	mon->find_route(target_player);
	mon->check_target(target_player);
}

int main(){
	int mon_count, i;
	player target_player_dummy;
	
	target_player_dummy.set_location(dis(gen), dis(gen)); // 랜덤으로 거리 생성
	monster_factory::initialize_monster();					// create_monster(forest_terrain, 2); 등등
	
	mon_count = monster_factory::get_monster_count();		// 몬스터 개수 반환
	
	for(i=0; i<mon_count; i++){
		// 몬스터 종류와 상관 없이 전체 몬스터를 순회하면서 동일한 흐름을 실행
		cout << endl << endl;
		monster_routine(monster_factory::get_monster(i), target_player_dummy);
	}
	
	monster_factory::destroy_monster();
	
	return 0;
}