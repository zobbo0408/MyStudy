#include<iostream>
#include<deque>

using namespace std;

int main(){
	deque<int> myDeque;
	
	myDeque.push_back(2);
	myDeque.push_back(3);
	myDeque.push_back(4);
	
	myDeque.push_front(1);
	myDeque.push_front(0);
	
	cout << "출력" << endl;
	for (const int& value : myDeque) {
		cout << value << " ";
	}
	cout << endl;
	
	myDeque.pop_front();
	myDeque.pop_back();
	
	cout << "삭제 후 출력" << endl;
	for (const int& value : myDeque) {
		cout << value << " ";
	}
	cout << endl;
	
	cout << "deque 크기 : " << (myDeque.empty() ? "예" : "아니오") << endl;
	
	cout << "deque 첫 번째 원소 " << myDeque.front() << endl;
	cout << "deque 마지막 원소 " << myDeque.back() << endl;
	
	return 0;
}