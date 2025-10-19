#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> myStack;
	
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	
	cout << "맨 위 요소 : " << myStack.top() << endl;
	
	myStack.pop();
	cout << "맨 위 요소 제거 후, 새로운 맨 위 요소 : " << myStack.top() << endl;
	
	cout << "스택 크기 : " << myStack.size() << endl;
	
	if(myStack.empty()) {
		cout << "스택이 비었습니다." << endl;
	}
	else {
		cout << "스택이 비어있지 않습니다." << endl;
	}
	
	return 0;
}