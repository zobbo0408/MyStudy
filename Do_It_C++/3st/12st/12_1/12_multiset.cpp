#include <iostream>
#include <set>
using namespace std;

int main() {
	multiset<int> myMultiset;
	
	myMultiset.insert(5);
	myMultiset.insert(2);
	myMultiset.insert(5);
	
	int count = myMultiset.count(5);
	
	cout << "저장되어 있는 5의 개수 : " << count << endl;
	
	for(auto it = myMultiset.begin(); it != myMultiset.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	
	int size = myMultiset.size();
	cout << "multiset의 크기 : " << size << endl;
	
	return 0;
}