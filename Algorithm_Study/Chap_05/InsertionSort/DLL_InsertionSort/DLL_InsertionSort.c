#include "DoublyLinkedList.h"


void InsertionSort(Node** Head)
{	
	if(*Head == NULL || (*Head)->NextNode == NULL)
		return ; //  리스트가 비었거나 노드가 하나 뿐임을 나타냄.
	
	Node* Sorted_Tail = *Head; // 정렬된 부분의 마지막 노드
	Node* Current = (*Head)->NextNode; // 정렬되지 않은 첫 노드
	
	while(Current != NULL)
	{
		Node* Next_to_sort = Current->NextNode; // 다음에 삽입할 노드를 미리 저장.
		
		// Case 1 : 현재 노드가 정렬된 부분의 마지막보다 크거나 같으면, 이미 정렬됨.
		if(Current->Data >= Sorted_Tail->Data)
			Sorted_Tail = Current;
		
		// Case 2 : 현재 노드를 정렬된 부분에 삽입해야 함.
		else
		{
			// 리스트에서 Current 노드 분리 (중요!)
			// Current가 Sorted_Tail의 다음 노드이므로 Sorted_Tail->NextNode를 Next_to_sort로 연결
			Sorted_Tail->NextNode = Next_to_sort;
			if(Next_to_sort != NULL)
				Next_to_sort->PrevNode = Sorted_Tail;
			
			// 삽입할 위치 탐색하는 노드
			Node* Search = *Head;
			while(Search != NULL && Search->Data < Current->Data)
				Search = Search->NextNode;
			
			// Search는 Current가 삽입될 위치 앞 노드임
			if(Search == *Head)
			{
				Current->NextNode = *Head;
				(*Head)->PrevNode = Current;
				Current->PrevNode = NULL;
				*Head = Current; // Head 업데이트
			}
			else 
			{
				Current->NextNode = Search;
				Current->PrevNode = Search->PrevNode;
				
				Search->PrevNode->NextNode = Current;
				Search->PrevNode = Current;
			}
		}
		Current = Next_to_sort; // 다음 노드로 이동.
	}
}


int main(void) {
	int i=0;
	int Count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;
	
	NewNode = DLL_CreateNode(6);
	DLL_AppendNode(&List, NewNode);
	NewNode = DLL_CreateNode(4);
	DLL_AppendNode(&List, NewNode);
	NewNode = DLL_CreateNode(2);
	DLL_AppendNode(&List, NewNode);
	NewNode = DLL_CreateNode(1);
	DLL_AppendNode(&List, NewNode);
	NewNode = DLL_CreateNode(3);
	DLL_AppendNode(&List, NewNode);
	NewNode = DLL_CreateNode(5);
	DLL_AppendNode(&List, NewNode);
	
	Count = DLL_GetNodeCount(List);
	
	
	printf("Current List...\n");
	
	for(i=0; i<Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf(" %d", Current->Data);
	}
	printf("\n");
	
	InsertionSort(&List);
	
	printf("\nInsertionSorting List...\n");
	
	for(i=0; i<Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf(" %d", Current->Data);
	}
	
	printf("\n");
	printf("\nDestroying List...\n");
	
	for(i=0; i<Count; i++) {
		Current = DLL_GetNodeAt(List, i);
		
		if(Current != NULL) {
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}
	
	return 0;
}