#include<iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	
	vector<int>::const_iterator const_it = vec.cbegin();
	cout << *const_it << endl;
	
	++const_it;
	cout << *const_it << endl;
	
	const_it = vec.cend();
	--const_it;
	cout << *const_it << endl;
	
	return 0;
}