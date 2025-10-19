#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map <string, int> scores;
	
	scores.insert(make_pair("Bob", 85));
	scores.insert(make_pair("Jane", 90));
	scores.insert(make_pair("Tom", 70));
	
	cout << "map 크기 : " << scores.size() << endl << endl;
	
	auto it = scores.find("Bob");
	if(it != scores.end()) {
		cout << "Bob의 점수 검색 결과 : " << it->second << endl;
	}
	else {
		cout << "Bob의 점수는 저장되어 있지 않음" << endl;
	}
	cout << endl;
	
	scores.erase("Bob");
	
	cout << "Bob의 정보 제거 후 map 크기 : " << scores.size() << endl << endl;
	
	cout << "---map의 모든 정보 출력---" << endl;
	for(auto& pair : scores) {
		cout << pair.first << " : " << pair.second << endl;
	}
	
	return 0;
}