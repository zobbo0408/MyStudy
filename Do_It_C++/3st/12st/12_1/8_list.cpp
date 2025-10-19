#include<iostream>
#include<list>

using namespace std;

int main(){
	list<int> myList;
	myList.push_back(2);
	myList.push_back(3);
	myList.push_back(4);
	
	myList.push_front(1);
	myList.push_front(0);
	
	cout << "리스트 출력" ; 
	for (const int& value : myList) {
		cout << value << " ";
	}
	cout << endl;
	
	myList.pop_front();
	myList.pop_back();
	
	cout << "삭제 후 리스트 출력" ; 
	for (const int& value : myList) {
		cout << value << " ";
	}
	cout << endl;
	
	cout << "리스트 크기 확인" << endl;
	cout << myList.size() << endl;
	
	//리스트가 비었는지 확인
	cout << "리스트가 비었는가? " << (myList.empty() ? "예" : "아니오") << endl;
	
	return 0;
}