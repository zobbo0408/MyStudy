#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Person {
	string name;
	int age;
	float height;
	float weight;
};

void print_vector_all(vector<Person>& vec) {
	for(vector<Person>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << "이름 : " << it->name << "\t" << "나이 : " << it->age
			<< ", 키 : " << it->height << ", 몸무게 : " << it->weight << endl;
	}
}

bool compare(const Person& lhs, const Person& rhs) {
	return lhs.age < rhs.age; // 첫번째 인자의 나이가 적으면 true
}

int main() {
	Person P[5] = {
      {"Brain", 24, 180, 70},
      {"Jessica", 22, 165, 55},
      {"James", 30, 170, 65},
      {"Tom", 12, 155, 46},
      {"Mary", 18, 172, 62}
  	};
	
	vector<Person> vec;
	vec.push_back(P[0]);
	vec.push_back(P[1]);
	vec.push_back(P[2]);
	vec.push_back(P[3]);
	vec.push_back(P[4]);
	
	cout << "---정렬 전---" << endl;
	print_vector_all(vec);
	cout << endl;
	
	// C++에서 함수의 이름은 그 함수의 주소를 나타낸다
	// compare는 함수 자체를 가리키는 포인터 역할을 하고, 
	// compare()처럼 괄호를 붙이면 함수 호출을 의미
	
	// template< class RandomIt, class Compare >
	// void sort( RandomIt first, RandomIt last, Compare comp );
	// 아래의 comp 인자는 함수 포인터로 compare 함수의 주소를 전달하는 것과 같은 효과
	
	// compare()로 쓴다면 함수가 실행되어 반환값을 전달하려 하기에 함수 포인터 타입과 맞지 않아 오류가 발생.
	sort(vec.begin(), vec.end(), compare);
	print_vector_all(vec);
	
	return 0;
}