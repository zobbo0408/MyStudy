#include <iostream>

using namespace std;

class character {
public:
    character() : hp(100), power(100){}; // 체력과 파워 직접 초기화
	
	// 플레이어와 몬스터 둘 다 적용, 몬스터는 재정의 해야하므로 가상함수 선언
    virtual void get_damage(int _damage){
		reduce_data(hp, _damage);
	};
	
	// 플레이어만 해당하므로 가상함수 선언 x
	void lose_power(int _lose){
		reduce_data(power, _lose);
	};
    int get_hp() { return hp; };
    int get_power() { return power; };
	void set_hp(int _hp){hp = _hp;};
	void set_power(int _power){power = _power;};
	

protected:
    int hp;
    int power;
	// 체력과 파워를 줄일 때 사용하는 공통 함수
	void reduce_data(int &attribute, int _damage){
		if(attribute == 0)
			return ;
		attribute -= _damage;
		attribute = attribute < 0 ? 0 : attribute; // 결과(체력 || 파워)가 0보다 작으면 0 반환
	};
};

class player : public character {
public:
    player() {};
	// 플레이어가 적을 공격하는 멤버함수
	void attack(character& enemy){enemy.get_damage(5);};
};

class monster_c : public character {
public:
	monster_c() : clock(60){set_hp(1000);};
	monster_c& attack(player& target_player) ;
	monster_c& reduce_power(player& target_player);
    //상속받은 함수 오버라이딩, 2초간 무적임을 나타내기 위해 상속 후 재정의 하여, 다형성을 나타냄
    virtual void get_damage(int _damage) override;
	void ticktok();
	
	private:
	int clock;
};

// 시간이 수동으로 흐름을 나타내는 함수
void monster_c::ticktok(){
	clock++;
	clock %= 60;
}

void monster_c::get_damage(int _damage){
	if(clock < 3)
		return; // 1분 중 처음 2초 간 공격을 받지 않음
	
	 reduce_data(hp, _damage);
}

monster_c& monster_c :: attack(player& target_player){
	target_player.get_damage(1);
	return *this; // 체이닝을 위한 자기 자신 반환
}

monster_c& monster_c::reduce_power(player & target_player){
	target_player.lose_power(1);
	return *this; // 체이닝을 위한 자기 자신 반환
}

void print(string title, monster_c mon, player user){
	cout << title << endl;
    cout << "Monster C: hp(" << mon.get_hp() << "), power(" << mon.get_power() << ")" << endl;
    cout << "Player: hp(" << user.get_hp() << "), power(" << user.get_power() << ")" << endl;
}

int main() {

    monster_c mon;
	player user;
  
	print("게임 시작 전", mon, user);

    for (int i = 0; i < 60; ++i) { // 반복문 1회 반복을 1초로 가정
      user.attack(mon);
      mon.attack(user).reduce_power(user).ticktok();
    }

    print("게임 종료 후", mon, user);

  return 0;
}