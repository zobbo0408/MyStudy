#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> vec;
	for(int i=0; i<5; i++){
		vec.push_back(i);
	}
	
	for (vector<int>::reverse_iterator r_it = vec.rbegin(); r_it != vec.rend(); r_it++){
		cout << *r_it << endl;
	}
}