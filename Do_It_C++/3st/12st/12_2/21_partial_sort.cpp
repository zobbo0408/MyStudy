#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector <int> numbers = {7, 2, 5, 1, 8, 9, 3, 6, 4};
	
	// numbers 벡터에서 가장 작은 3개의 요소만 정렬
	// 순서대로 {정렬 범위의 시작을 가리키는 반복자, 정렬 범위의 끝을 가리키는 반복자, 정렬 종료 범위의 반복자}
	partial_sort(numbers.begin(), numbers.begin() + 4, numbers.end());
	
	// 정렬된 결과 출력
	for(vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	
	return 0;
}