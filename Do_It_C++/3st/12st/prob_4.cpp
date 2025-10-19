/*
문제 4 벡터 생성과 사용자 정의 데이터 형식 저장하기
이름, HP, MP 속성을 가지는 몬스터 구조체를 만들고, 
벡터 컨테이너에 서로 다른 몬스터 객체 10마리를 저장합니다. 
그리고 컨테이너에 저장된 모든 몬스터를 출력해 보세요
*/

#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

typedef struct mon_struct {
	string name;
	int HP;
	int MP;
} Monster;

Monster CreateMonster(mt19937& gen){
	vector<string> names = { "슬라임", "고블린", "오우거", "드래곤", "스켈레톤", "코볼트", "마법사", "악마", "페어리"};
	uniform_int_distribution<int> name_dist(0, names.size() - 1);
	uniform_int_distribution<int> HP_dist(0, 150);
	uniform_int_distribution<int> MP_dist(0, 150);
	
	string name = names[name_dist(gen)];
	int HP = HP_dist(gen);
	int MP = MP_dist(gen);
	
	return {name, HP, MP};
}

int main() {
	random_device rd;
	mt19937 gen(rd());
	
	vector<Monster> mon_inst;
	
	for (int i=0; i<10; i++) {
		mon_inst.push_back(CreateMonster(gen));
	}
	
	
	cout << "Monster List..." << endl << endl;
	for (auto& monster : mon_inst) {
		cout << "이름 : " << monster.name << ", HP : " << monster.HP << ", MP : " << monster.MP << endl;
	}
	
	
	return 0;
}