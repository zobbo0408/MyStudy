#include "LinkedQueue.h"

void LQ_CreateQueue (LinkedQueue** Queue) {
	// 큐를 자유저장소(힙 영역)에 할당
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

void LQ_DestroyQueue (LinkedQueue* Queue) {
	while( !LQ_IsEmpty(Queue) ){
		// 큐의 노드들을 비운다.
		Node* Popped = LQ_Dequeue(Queue);
		LQ_DestroyNode(Popped);
	}
	
	// 비워진 큐를 힙 영역에서 해제
	free(Queue);
}

Node* LQ_CreateNode (Vertex* NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	// NewNode->Data = (char*)malloc(strlen(NewData) + 1);
	// // char* 형이므로 \0문자 자리를 만들기 위해 strlen(NewData) + 1크기를 힙 영역에 할당.
	
	// strcpy(NewNode->Data, NewData);
	
	// NewData는 이미 동적으로 할당된 Vertex 구조체에 대한 포인터입니다. 
	// 큐의 노드는 이 포인터만 저장하면 되므로, 굳이 Vertex를 위한 새로운 메모리를 할당하고 내용을 복사할 필요가 없습니다.
	NewNode->Data = NewData; 
	NewNode->NextNode = NULL;
	
	return NewNode;
}

void LQ_DestroyNode (Node* _Node) {
	// _Node의 데이터(Vertex*)는 큐 외부에서 관리되므로 해제하지 않음
	// free (_Node->Data); // 큐 노드에 포함된 정점까지 파괴
	free (_Node); 
}

void LQ_Enqueue (LinkedQueue* Queue, Node* NewNode) {
	if (Queue->Front == NULL) {
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		Queue->Count ++;
	}
	
	else {
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
		Queue->Count ++;
	}
}

Node* LQ_Dequeue (LinkedQueue* Queue) {
	// LQ_Dequeue() 함수가 반환할 최상위 노드
	Node* Front = Queue->Front;
	
	if(Queue->Front->NextNode == NULL) {
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	
	else {
		Queue->Front = Queue->Front->NextNode;
	}
	
	Queue->Count --;
	
	return Front;
}

int LQ_IsEmpty (LinkedQueue* Queue) {
	return (Queue->Front == NULL);
}