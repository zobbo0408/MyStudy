/*
문제 5 임의의 순서로 정렬하기
[문제 4]의 코드를 이어서 활용합니다. ‘이름 > HP > MP’ 순으로 정렬하는 함수를 만들어 보세요. 
그리고 해당 함수가 잘 동작하는지 컨테이너에 저장된 몬스터들을 모두 출력해서 확인해 보세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

// true에 맞게 비교 즉, 오름차순.
bool compare(Monster& lhs, Monster& rhs) {
	if(lhs.name != rhs.name) 
		return lhs.name < rhs.name;
	else if(lhs.HP != rhs.HP)
		return lhs.HP < rhs.HP;
	else
		return lhs.MP < rhs.MP;
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
	
	
	sort(mon_inst.begin(), mon_inst.end(), compare); // 사용자 정의 비교함수를 사용한 퀵 정렬
	
	cout << endl << "using quick_sort..." << endl;
	for (auto& monster : mon_inst) {
		cout << "이름 : " << monster.name << ", HP : " << monster.HP << ", MP : " << monster.MP << endl;
	}
	
	return 0;
}