#include <iostream>

using namespace std;

class Node {
	public :
	Node(int val) : Data(val), NextNode(nullptr), PrevNode(nullptr) {};
	
	int Data;
	Node* PrevNode;
	Node* NextNode;
};

class DoublyLinkedList {
	public :
	DoublyLinkedList() : Head(nullptr) {};
	~DoublyLinkedList();
	
	void DLL_AppendNode(int val);
	void DLL_InsertAfter(Node* Current, int val);
	void DLL_InsertNewHead(int val);
	void DLL_RemoveNode(int val);
	Node* DLL_GetNodeAt(int idx);
	int getCount();
    void printList();
	
	private:
	Node* Head;
};

DoublyLinkedList::~DoublyLinkedList() {
	Node* Current = Head;
	while(Current) {
		Node* NextNode = Current->NextNode;
		delete Current;
		Current = NextNode;
	}
}

void DoublyLinkedList::DLL_AppendNode(int val) {
	Node* NewNode = new Node(val);
	if(!Head) {
		Head = NewNode;
	}
	else {
		Node* Tail = Head;
		while(Tail->NextNode) {
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
	}
}

void DoublyLinkedList::DLL_InsertAfter(Node* Current, int val) {
	Node* NewNode = new Node(val);
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;
	if(Current->NextNode) {
		Current->NextNode->PrevNode = NewNode; 
		// Current의 다음 노드가 nullptr이 아니면 Current의 다음 노드의 이전노드를 
		// NewNode로 지정해줘야 함.
	}
	Current->NextNode = NewNode;
}

void DoublyLinkedList::DLL_InsertNewHead(int val) {
	Node* NewNode = new Node(val);
	if(!Head) {
		Head = NewNode;
	}
	else {
		NewNode->NextNode = Head;
		Head->PrevNode = NewNode;
		Head = NewNode;
	}
}

void DoublyLinkedList::DLL_RemoveNode(int val) {
	if(Head->Data == val) {
		Node* Remove = Head;
		Head = Remove->NextNode;
		if(Head){
			Head->PrevNode = nullptr;
		}
		Remove->NextNode = nullptr;
		Remove->PrevNode = nullptr;
		delete Remove;
	}
	else {
		Node* Current = Head;
		
		while(Current->NextNode && Current->NextNode->Data != val){
			Current = Current->NextNode;
		}
		
		Node* Remove = Current->NextNode;
		Node* Temp = Remove;
		if(Remove->NextNode != nullptr){
			Remove->PrevNode->NextNode = Temp->NextNode;
		}
		if(Remove->PrevNode != nullptr){
			Remove->NextNode->PrevNode = Temp->PrevNode;
		}
		Remove->PrevNode = nullptr;
		Remove->NextNode = nullptr;
		delete Remove;
	}
}

Node* DoublyLinkedList::DLL_GetNodeAt(int idx){
	Node* Current = Head;
	int Count = 0;
	while(Current && Count < idx){
		Current = Current->NextNode;
		Count++;
	}
	return Current;
}

int DoublyLinkedList::getCount(){
	Node* Current = Head;
	int Count = 0;
	while(Current) {
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}

void DoublyLinkedList::printList() {
    Node* Current = Head;
    while (Current) {
        cout << Current->Data << " <-> ";
        Current = Current->NextNode;
    }
    cout << "NULL" << endl;
}

int main() {
    DoublyLinkedList list;
    list.DLL_AppendNode(0);
    list.DLL_AppendNode(1);
    list.DLL_AppendNode(2);
    list.DLL_AppendNode(3);
    list.DLL_AppendNode(4);
    
    list.DLL_InsertNewHead(-1);
    list.DLL_InsertNewHead(-2);
    
    list.printList();
    
    std::cout << "Total nodes: " << list.getCount() << std::endl;
    
    return 0;
}