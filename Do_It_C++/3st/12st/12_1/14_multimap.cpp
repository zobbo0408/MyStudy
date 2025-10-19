#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	multimap<string, int> scores;
	
	scores.insert(make_pair("Bob", 70));
	scores.insert(make_pair("Jane", 90));
	scores.insert(make_pair("Tom", 80));
	scores.insert(make_pair("Bob", 100));
	
	cout << "multimap의 크기 : " << scores.size() << endl << endl;
	
	int count = scores.count("Bob");
	cout << "저장되어 있는 Bob 점수의 갯수 : " << count << endl;
	
	auto range = scores.equal_range("Bob");
	if(range.first != scores.end()) {
		cout << "Bob의 모든 점수 : ";
		for(auto it = range.first; it != range.second; it++){
			cout << it->second << " ";
		}
		cout << endl;
	}
	else {
		cout << "Bob의 점수는 저장되어 있지 않음" << endl;
	}
	cout << endl;
	
	scores.erase("Bob"); // 모든 원소 삭제
	
	cout << "Bob의 정보 삭제 후 multimap의 크기 : " << scores.size() << endl << endl;
	
	cout << "---multimap의 모든 정보 출력---" << endl;
	for(auto& pair : scores) {
		cout << pair.first << " : " << pair.second << endl;
	}
	
	return 0;
}