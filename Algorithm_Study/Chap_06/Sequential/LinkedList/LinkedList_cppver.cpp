#include <iostream>

using namespace std;

class Node {
public :
	int Data;
	Node* NextNode;
	Node(int value) : Data(value), NextNode(nullptr) {};	
};

class LinkedList {
public:
	LinkedList() : Head(nullptr) {};
	~LinkedList();
	
	void append(int value);
    void insertAtHead(int value);
    void remove(int value);
    Node* getNodeAt(int index);
    int getCount();
    void printList();
	
private :
	Node* Head;
};

LinkedList::~LinkedList() {
	Node* Current = Head;
	while (Current) {
		Node* NextNode = Current->NextNode;
		delete Current;
		Current = NextNode;
	}
}

void LinkedList::append(int value) {
	Node* NewNode = new Node(value);
	if(!Head) {
		Head = NewNode;
	}
	else {
		Node* Tail = Head;
		while (Tail->NextNode) {
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

void LinkedList::insertAtHead(int value) {
	Node* NewNode = new Node(value);
	if(!Head) {
		Head = NewNode;
	}
	else {
		NewNode->NextNode = Head;
		Head = NewNode;
	}
}

void LinkedList::remove(int value) {
	if(!Head) {
		return ;
	}
	if(Head->Data == value) {
		Node* temp = Head;
		Head = Head->NextNode;
		delete temp;
		return ;
	}
	Node* Current = Head;
	while(Current->NextNode && Current->NextNode->Data != value) {
		Current = Current->NextNode;
	}
	if(Current->NextNode) {
		Node* temp = Current->NextNode;
		Current->NextNode = temp->NextNode;
		delete temp;
	}
}

Node* LinkedList::getNodeAt(int index) {
    Node* Current = Head;
    int count = 0;
    while (Current && count < index) {
        Current = Current->NextNode;
        count++;
    }
    return Current;
}

int LinkedList::getCount() {
    int count = 0;
    Node* Current = Head;
    while (Current) {
        count++;
        Current = Current->NextNode;
    }
    return count;
}

void LinkedList::printList() {
    Node* Current = Head;
    while (Current) {
        std::cout << Current->Data << " -> ";
        Current = Current->NextNode;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    LinkedList list;
    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    
    list.insertAtHead(-1);
    list.insertAtHead(-2);
    
    list.printList();
    
    std::cout << "Total nodes: " << list.getCount() << std::endl;
    
    return 0;
}