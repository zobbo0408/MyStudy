#include "DoublyLinkedList.h"

Node* DLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;
	
	return NewNode;
}

void DLL_DestroyNode(Node* Node) {
	free(Node);
}

void DLL_AppendNode(Node** Head, Node* NewNode) {
	if((*Head) == NULL) {
		*Head = NewNode;
	}
	else {
		Node* Tail;
		Tail = *Head;
		
		while (Tail->NextNode != NULL) {
			Tail = Tail->NextNode;
		}
		
		// NewNode->NextNode = Tail->NextNode; // 어차피 널
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
	}
}

void DLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;
	
	if(Current->NextNode != NULL) {
		Current->NextNode->PrevNode = NewNode;
	}
	
	Current->NextNode = NewNode;
}

void DLL_InsertNewHead(Node** Head, Node* NewNode) {
	if ((*Head) == NULL) {
		*Head = NewNode;
	}
	else {
		NewNode->NextNode = *Head;
		(*Head) = NewNode;
	}
}

void DLL_RemoveNode(Node** Head, Node* Remove) {
	if((*Head) == Remove) {
		
		(*Head) = Remove->NextNode;
		if((*Head) != NULL) {
			(*Head)->PrevNode = NULL;
		}
		Remove->NextNode = NULL;
		Remove->PrevNode = NULL;
	}
	else {
		Node* Temp = Remove;
		
		if (Remove->PrevNode != NULL) {
			Remove->PrevNode->NextNode = Temp->NextNode;
		}
		if(Remove->NextNode != NULL) {
			Remove->NextNode->PrevNode = Temp->PrevNode;
		}
		
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

Node* DLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;
	
	while(Current->NextNode != NULL && (Location-- > 0)) {
		Current = Current->NextNode;
	}
	
	return Current;
}

int DLL_GetNodeCount(Node* Head) {
	unsigned int Count = 0;
	Node* Current = Head;
	
	while (Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}
	
	return Count;
}
