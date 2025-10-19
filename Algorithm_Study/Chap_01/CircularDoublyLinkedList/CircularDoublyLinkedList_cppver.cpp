#include <iostream>
using namespace std;

// 원형 이중 연결 리스트는 가장 마지막 노드의 NextNode가 Head를 가리킴
// Head의 PrevNode는 가장 마지막 노드를 가리킴.
// 처음 선언하고 노드가 Head만 있을 땐 각 포인터들이 자신을 가리킨다. 
// 클래스에서 선언할 땐 똑같이 nullptr로 초기화. 멤버 함수에서 위 조건을 맞춤.

class Node {
	public:
	Node(int val) : Data(val), PrevNode(nullptr), NextNode(nullptr) {};
	int Data;
	Node* PrevNode;
	Node* NextNode;
};

class CircularDoublyLinkedList {
	public:
	CircularDoublyLinkedList() : Head(nullptr) {};
	~CircularDoublyLinkedList();
	
	void CDLL_AppendNode(int val);
	void CDLL_InsertAfter(Node* Current, int val);
	void CDLL_InsertNewHead(int val);
	void CDLL_RemoveNode(int val);
	Node* CDLL_GetNodeAt(int idx);
	int getCount();
    void printList();
	
	private:
	Node* Head;
};

CircularDoublyLinkedList::~CircularDoublyLinkedList() {
	Node* Current = Head;
	do {
		Node* NextNode = Current->NextNode;
		delete Current;
		Current = NextNode;
	} while(Current != Head);
	
	Head = nullptr;
}

void CircularDoublyLinkedList::CDLL_AppendNode(int val) {
	Node* NewNode = new Node(val);
	if(Head == nullptr) {
		Head = NewNode;
		Head->PrevNode = Head;
		Head->NextNode = Head;
	}
	else {
		Node* Tail = Head->PrevNode;

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
		NewNode->NextNode = Head;
		Head->PrevNode = NewNode;
	}
}

void CircularDoublyLinkedList::CDLL_InsertAfter(Node* Current, int val) {
	Node* NewNode = new Node(val);
	if(Current->NextNode != nullptr){
		Current->NextNode->PrevNode = NewNode;
		NewNode->NextNode = Current->NextNode;
	}
	Current->NextNode = NewNode;
	NewNode->PrevNode = Current;
}

void CircularDoublyLinkedList::CDLL_InsertNewHead(int val) {
	Node* NewNode = new Node(val);
	if(Head == nullptr) {
		Head = NewNode;
		Head->NextNode = Head;
		Head->PrevNode = Head;
	}
	else {
		Head->PrevNode->NextNode = NewNode;
		NewNode->PrevNode = Head->PrevNode;;
		Head->PrevNode = NewNode;
		NewNode->NextNode = Head;
		
		Head = NewNode;
	}
}

void CircularDoublyLinkedList::CDLL_RemoveNode(int val) {
	if(Head->Data == val) {
		Node* Remove = Head;
		Head = Remove->NextNode;
		Remove->NextNode = nullptr;
		Remove->PrevNode = nullptr;
		delete Remove;
	}
	else {
		Node* Current = Head;
		
		while (Current->NextNode->Data != val) {
			Current = Current->NextNode;
		}
		
		Node* Remove = Current->NextNode;
		Remove->PrevNode->NextNode = Remove->NextNode;
		Remove->NextNode->PrevNode = Remove->PrevNode;
		
		Remove->PrevNode = nullptr;
		Remove->NextNode = nullptr;
		delete Remove;
	}
}

Node* CircularDoublyLinkedList::CDLL_GetNodeAt(int idx) {
	Node* Current = Head;
	int Count = 0;
	
	while(Count != idx){
		Current = Current->NextNode;
		Count++;
	}
	
	return Current;
}

int CircularDoublyLinkedList::getCount() {
	Node* Current = Head;
	int Count = 0;
	
	do {
        Count++;
        Current = Current->NextNode;
    } while (Current != Head);
	
	return Count;
}

void CircularDoublyLinkedList::printList() {
    if (!Head) {
        cout << "List is empty." << endl;
        return;
    }

    Node* Current = Head;
    do {
        cout << Current->Data << " <-> ";
        Current = Current->NextNode;
    } while (Current != Head);

    cout << "(HEAD)" << endl;
}

int main() {
    CircularDoublyLinkedList list;
    list.CDLL_AppendNode(0);
    list.CDLL_AppendNode(1);
    list.CDLL_AppendNode(2);
    list.CDLL_AppendNode(3);
    list.CDLL_AppendNode(4);
    
    list.CDLL_InsertNewHead(-1);
    list.CDLL_InsertNewHead(-2);
    
    list.printList();
    
    std::cout << "Total nodes: " << list.getCount() << std::endl;
    
    return 0;
}