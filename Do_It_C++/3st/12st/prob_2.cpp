/*
문제 2 스택 다루기
다음 코드처럼 실수가 저장된 스택이 주어졌을 때 
스택에서 가장 작은 값을 찾아 출력하는 코드를 작성해 보세요.
*/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
  stack<double> myStack;
  myStack.push(3.14);
  myStack.push(2.71);
  myStack.push(0.98);
  myStack.push(1.23);

  // 스택에서 가장 작은 값을 찾아 출력하는 코드를 작성해 보세요.
	cout << myStack.top() << endl;
	double num;
	num = myStack.top();
	for (int i=0; i < myStack.size(); i++) {
		myStack.pop();
		if(num >= myStack.top()) {
			num = myStack.top();
		}
	}
	
	cout << "가장 작은 값 : " << num << endl;
	

  return 0;
}