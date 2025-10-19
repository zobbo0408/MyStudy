#include<iostream>

using namespace std;

class character{
public:
	character(){
		cout << "character 클래스 생성자 호출!" << endl;
	}
};

int main(){
	character parkjoonyeong;
	
	return 0;
}