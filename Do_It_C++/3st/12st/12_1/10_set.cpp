#include <iostream>
#include <set>
using namespace std;

int main(){
	set<int> mySet;
	
	mySet.insert(5);
	mySet.insert(2);
	mySet.insert(8);
	
	if(mySet.find(5) != mySet.end()){
		cout << "5는 세트에 저장되어 있음." << endl;
	}
	
	for (auto it = mySet.begin(); it != mySet.end(); ++it){
		cout << *it << " " << endl;
	}
	
	int size = mySet.size();
	cout << "set 크기 : " << size << endl;
	
	return 0;
}