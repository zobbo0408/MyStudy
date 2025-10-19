#include "CircularDoublyLinkedList.h"

int main(void) {
	int i=0;
	int Count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;
	
	for (i=0; i<5; i++) {
		NewNode = CDLL_CreateNode(i);
		CDLL_AppendNode(&List, NewNode);
	}
	
	NewNode = CDLL_CreateNode(-1);
	CDLL_InsertNewHead(&List, NewNode);
	
	NewNode = CDLL_CreateNode(-2);
	CDLL_InsertNewHead(&List, NewNode);
	
	Count = CDLL_GetNodeCount(List);
	for(i=0; i<Count; i++){
		Current = CDLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}
	
	printf("\nInserting 3000 After [2]...\n\n");
	
	Current = CDLL_GetNodeAt(List, 2);
	NewNode = CDLL_CreateNode(3000);
	
	CDLL_InsertAfter(Current, NewNode);
	
	Count = CDLL_GetNodeCount(List);
	for(i=0; i<Count; i++){
		Current = CDLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}
	
	printf("\nDestroying List...\n");
	
	for(i=0; i<Count; i++) {
		Current = CDLL_GetNodeAt(List, i);
		
		if(Current != NULL) {
			CDLL_RemoveNode(&List, Current);
			CDLL_DestroyNode(Current);
		}
	}
	
	return 0;
}