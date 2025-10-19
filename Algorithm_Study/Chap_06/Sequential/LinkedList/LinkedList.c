#include "LinkedList.h"

Node* SLL_CreateNode(ElementType NewData){
	Node* NewNode = (Node*)malloc(sizeof(Node)); // 힙 영역에 노드 생성
	NewNode -> Data = NewData; // 데이터 저장
	NewNode -> Count = 0;
	NewNode -> NextNode = NULL; // 다음 노드에 대한 포인터를 NULL로 초기화
	
	return NewNode;
}

void SLL_DestroyNode(Node* Node){
	free(Node); // 힙 영역에 할당된 노드의 메모리 해제
}

// Head를 Node*로 받았다면, 함수 내부의 Head는 List가 가리키는 값을 복사받을 뿐, List 변수 자체와는 연결되지 않습니다. 
// List라는 포인터와 연결하여 그 내부의 값이 수정되야 함(포인터로 값의 주소와 연결해서...따라서 2중포인터!!!)
void SLL_AppendNode(Node** Head, Node* NewNode){
	// 헤드 노드가 NULL이라면 새로운 노드가 헤드가 된다.
	if((*Head) == NULL) {
		*Head = NewNode;
	}
	else {
		// 테일을 찾아 NewNode를 연결한다.
		Node* Tail = (*Head);
		while(Tail->NextNode != NULL) {
			Tail = Tail->NextNode;
		}
		
		Tail->NextNode = NewNode;
	}
}

// Current 노드의 뒤에 NewNode 삽입
void SLL_InsertAfter(Node* Current, Node* NewNode){
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewNode){
	if((*Head) == NULL) {
		(*Head) = NewNode;
	}
	else {
		NewNode->NextNode = (*Head);
		(*Head) = NewNode;
	}
}

void SLL_RemoveNode(Node** Head, Node* Remove){
	if((*Head) == Remove) {
		*Head = Remove->NextNode;
	}
	else {
		Node* Current = (*Head);
		while(Current != NULL && Current->NextNode != Remove) {
			Current = Current->NextNode;
		}
		
		if(Current != NULL) {
			Current->NextNode = Remove->NextNode;
		}
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location){
	Node* Current = Head;
	
	while(Current != NULL && (Location --) > 0) {
		Current = Current->NextNode;
	}
	
	return Current;
}

int SLL_GetNodeCount(Node* Head) {
	int Count = 0;
	Node* Current = Head;
	
	while(Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}
	
	return Count;
}

Node* SLL_SequentialSearch(Node* Head, int Target)
{
	Node* Current = Head;
	Node* Match = NULL;
	
	while(Current != NULL)
	{
		if(Current->Data == Target)
		{
			Match = Current;
			break;
		}
		else
			Current = Current->NextNode;
	}
	
	return Match; // 찾는 값을 갖고 있는 노드의 주소를 반환한다.
}

Node* SLL_MoveToFront(Node** Head, int Target)
{
	Node* Current = (*Head);
	Node* Previous = NULL;
	Node* Match = NULL;
	
	while (Current != NULL)
	{
		if(Current->Data == Target)
		{
			Match = Current;
			if(Previous != NULL) // Current != Head;
			{
				Previous->NextNode = Current->NextNode;
				Current->NextNode = (*Head);
				(*Head) = Current;
			}
			break;
		}
		
		else{
			Previous = Current;
			Current = Current->NextNode;
		}
	}
	
	return Match;
}

Node* SLL_Transpose(Node** Head, int Target)
{
	Node* Current = (*Head);
	Node* Previous = NULL;
	Node* PPrevious = NULL;
	Node* Match = NULL;
	
	while(Current != NULL)
	{
		if(Current->Data == Target)
		{
			Match = Current;
			if(Previous != NULL) // Current가 헤드인 경우 제외
			{
				if(PPrevious != NULL) // Current가 2번째인 경우 제외
					PPrevious->NextNode = Current;
				
				else
					(*Head) = Current;
				
				Previous->NextNode = Current->NextNode;
				Current->NextNode = Previous;
				break;
			}
		}
		
		else
		{
			if(Previous != NULL)
				PPrevious = Previous;
			Previous = Current;
			Current = Current->NextNode;
		}
	}
	
	return Match;
}
	
Node* SLL_FrequencyCount(Node** Head, int Target)
{
	if((*Head) == NULL)
		return NULL;
	
	Node* Current = (*Head);
	Node* Match = NULL;
	Node* Previous = NULL;
	Node* Temp = NULL;
	
	while(Current != NULL)
	{
		if(Current->Data == Target)
		{
			Match = Current;
			Match->Count ++;
			break;
		}
		
		else
		{
			Previous = Current;
			Current = Current->NextNode;	
		}
	}
	
	if(Match->Count > (*Head)->Count)
	{
			Previous->NextNode = Match->NextNode;
			Match->NextNode = (*Head);
			(*Head) = Match;
	}
	
	else
	{
		Current = (*Head)->NextNode;
		Temp = (*Head);
		
		while (Current != NULL)
		{
			if(Match->Count > Current->Count)
			{
				Previous->NextNode = Match->NextNode;
				Match->NextNode = Current;
				Temp->NextNode = Match;
				break;
			}
			
			else{
				Temp = Current;
				Current = Current->NextNode;
			}
		}
	}
	
	return Match;
}