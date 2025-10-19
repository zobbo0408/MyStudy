#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
	string name;
	int age;
	float height;
	float weight;
};

// 벡터에 저장된 사람 정보 출력
void print_person_all (vector<Person>& vec) {
	for(vector<Person>::iterator it = vec.begin(); it != vec.end(); it ++) {
		 cout << "이름: " << it->name << "\t > " << "나이: " << it->age << ", " << "키: " << it->height << ", " << "몸무게: " << it->weight << endl;
	}
}

int main() {
	Person p[5] = {
		{"Brain", 24, 180, 70},
		{"Jessica", 22, 165, 55},
		{"James", 30, 170, 65},
		{"Tom", 12, 155, 46},
		{"Mary", 18, 172, 62}
	};
	
	vector<Person> from_vector;
	from_vector.push_back(p[0]);
	from_vector.push_back(p[1]);
	from_vector.push_back(p[2]);
	from_vector.push_back(p[3]);
	from_vector.push_back(p[4]);
	
	// from_vector 출력
	cout << "---------from_vector---------" << endl;
	print_person_all(from_vector);
	cout << endl;
	
	vector<Person> to_vector;
	copy(from_vector.begin(), from_vector.end(), back_inserter(to_vector));
	
	// deep copy된 to_vector 출력
	cout << "---------to_vector---------" << endl;
	print_person_all(to_vector);
	cout << endl;
	
	// from_vector의 첫 번째 원소 수정
	from_vector[0] = {"Chris", 5, 110, 20};
	
	// 수정 후 from_vector 출력
	cout << "---------from_vector---------" << endl;
	print_person_all(from_vector);
	cout << endl;
	
	// 수정 후 to_vector 출력
	cout << "---------to_vector---------" << endl;
	print_person_all(to_vector);
	cout << endl;
	
	return 0;
}