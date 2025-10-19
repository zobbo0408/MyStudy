/*
문제 3 벡터에서 원소 찾기
다음 코드처럼 정수로 구성된 벡터가 주어졌을 때 
사용자에게 입력받은 숫자가 벡터에 포함되었는지를 출력하는 코드를 작성해 보세요.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> numbers = { 3, 8, 1, 6, 2, 7, 5, 4, 9 };

  int userInput;
  cout << "찾고자 하는 숫자를 입력하세요: ";
  cin >> userInput;

  // 사용자 입력값이 벡터에 포함되었지를 출력하는 코드를 작성해 보세요.
	vector<int>::iterator it = find(numbers.begin(), numbers.end(), userInput);
	
	if(it != numbers.end()) {
		cout << "해당 숫자의 위치는 " << distance(numbers.begin(), it) << " 입니다." << endl;
	}
	else {
		cout << "해당 숫자는 벡터에 없습니다." << endl;
	}

  return 0;
}