#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector <int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	
	for(int i=0; i<3; i++){
		cout << "vec의 " << i+1 << " 번째 원소 : " << vec[i] << endl;
	}
}