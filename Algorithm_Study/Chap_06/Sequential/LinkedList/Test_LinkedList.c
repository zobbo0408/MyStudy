#include "LinkedList.h"

int main(void) {
	int i=0;
	int Count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;
	Node* Target = NULL;
	
	for (i=0; i<5; i++) {
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(&List, NewNode);
	}
	
	NewNode = SLL_CreateNode(-1);
	SLL_InsertNewHead(&List, NewNode);
	
	NewNode = SLL_CreateNode(-2);
	SLL_InsertNewHead(&List, NewNode);
	
	Count = SLL_GetNodeCount(List);
	for(i=0; i<Count; i++){
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}
	
	printf("\nInserting 3000 After [2]...\n\n");
	
	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);
	
	SLL_InsertAfter(Current, NewNode);
	
	Count = SLL_GetNodeCount(List);
	for(i=0; i<Count; i++){
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}
	
	Target = SLL_FrequencyCount(&List, 3000);
	
	printf("\nTarget : %d, Count : %d\n\n", Target->Data, Target->Count);
	
	for(i=0; i<Count; i++){
		Current = SLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}
	
	printf("\nDestroying List...\n");
	
	for(i=0; i<Count; i++) {
		Current = SLL_GetNodeAt(List, i);
		
		if(Current != NULL) {
			SLL_RemoveNode(&List, Current);
			SLL_DestroyNode(Current);
		}
	}
	
	return 0;
}