#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> myQueue;
	
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);
	
	cout << "큐의 맨 앞 : " << myQueue.front() << endl;
	cout << "큐의 맨 뒤 : " << myQueue.back() << endl;
	
	myQueue.pop();
	
	cout << "큐의 맨 앞 : " << myQueue.front() << endl;
	cout << "큐의 맨 뒤 : " << myQueue.back() << endl;
	
	cout << "큐가 비어있나요? " << ((myQueue.empty()) ? "네" : "아니오") << endl;
	
	cout << "큐의 크기 : " << myQueue.size() << endl;
	
	return 0;
}