#include<iostream>
#include<vector>

using namespace std;

int main(){
	vector<int> vec;
	
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	
	vector<int>::iterator it = vec.begin();
	
	cout << *it << endl << endl;
	cout << *(it+0) << endl;
	cout << *(it+1) << endl;
	cout << *(it+2) << endl;
	cout << *(it+3) << endl;
	cout << *(it+4) << endl;
	
	return 0;
}