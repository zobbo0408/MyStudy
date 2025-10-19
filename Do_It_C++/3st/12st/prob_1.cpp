/*
문제 1 벡터 다루기
다음 코드처럼 정수로 구성된 벡터가 주어졌을 때 
홀수만 모두 제거하고 짝수만 남은 벡터를 출력하는 코드를 작성해 보세요.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1. 아래의 방법은 해당 부분을 삭제 후 앞으로 당겨지며, 해당 인덱스의 값이 홀수인지 확인을 못함.
// int main() {
// 	vector<int> numbers = {2, 7, 1, 8, 3, 6, 4, 5, 9};
	
// 	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
// 		if((*it % 2) != 0) {
// 			numbers.erase(it);
// 			if((*(it - 1) % 2) != 0) {
// 				numbers.erase(it);
// 			}
// 		}
// 	}
	
// 	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
// 		cout << *it << " ";
// 	}
// 	cout << endl;
	
// 	return 0;
// }

int main() {
	vector<int> numbers = {2, 7, 1, 8, 3, 6, 4, 5, 9};
	
	vector<int> evennumbers;
	
	for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		if((*it % 2) == 0) {
			evennumbers.push_back(*it);
		}
	}
	
	for (vector<int>::iterator it = evennumbers.begin(); it != evennumbers.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	
	return 0;
}