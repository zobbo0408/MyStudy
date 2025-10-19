#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare_pairs(const pair<int, string>& a, const pair<int, string>& b) {
	return a.first < b.first;
}

int main() {
	vector<pair<int, string>> pairs = {
		{5, "banana"},
		{2, "orange"},
		{5, "apple"},
		{3, "grape"}
	};
	
	// std::stable_sort를 사용하여 pair의 첫 번째 요소에 따라 안정 정렬
	// 안정 정렬 : 같은 원소가 정렬 후에도 원본의 순서와 일치, 즉 첫 번째 인자에 의해서만 정렬.
	// 불완전 정렬 : 같은 원소가 정렬 후에는 원본의 순서와 일치하지 않음 (ex. pairs가 apple이 먼저 나오는 경우)
	stable_sort(pairs.begin(), pairs.end(), compare_pairs);
	
	for (vector<pair<int, string>>::const_iterator it = pairs.begin(); it != pairs.end(); it++) {
		const pair<int, string>& pair = *it;
		cout << pair.first << " : " << pair.second << endl;
		// cout << it->first << " : " << it->second << endl;
	}
	
	return 0;
}