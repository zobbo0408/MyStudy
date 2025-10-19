#include "CircularQueue.h"

void CQ_CreateQueue (CircularQueue** Queue, int Capacity) {
	// 큐를 자유 저장소에 저장
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
	
	// 입력된 Capacity + 1 만큼의 노드를 자유 저장소에 저장
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node)*(Capacity+1));
	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

void CQ_DestroyQueue (CircularQueue* Queue) {
	free(Queue->Nodes);
	free(Queue);
}

void CQ_Enqueue (CircularQueue* Queue, ElementType Data) {
	int Position = 0;
	
	if(Queue->Rear == Queue->Capacity) {
		Position = Queue->Rear;
		Queue->Rear = 0;
	}
	else {
		Position = Queue->Rear++;
		// Position에 기존의 Queue->Rear를 초기화 후, Queue->Rear를 1 증가.
	}
	
	Queue->Nodes[Position].Data = Data;
}

ElementType CQ_Dequeue (CircularQueue* Queue) {
	int Position = Queue->Front;	// 기존의 전단 위치를 변수 Position에 초기화
	
	if(Queue->Front == Queue->Capacity) {
		Queue->Front = 0;
	}
	else { 
		Queue->Front ++;
	}
	
	return Queue->Nodes[Position].Data;
}

int CQ_GetSize (CircularQueue* Queue) {
	if (Queue->Front <= Queue->Rear)
		return Queue->Rear - Queue->Front;
	else
		// ex Rear가 마지막이고, 전단은 4번째라 가정 (Cap은 6) => 
		// 후단은 6번째 값(idx는 6)에 위치하지만 후단 변수(Queue->Rear)는 더미 (idx 0)에 위치
		// 따라서 0 + (6 - 4) + 1 => 3
		return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
}

int CQ_IsEmpty (CircularQueue* Queue) {
	return (Queue->Front == Queue->Rear);
}

int CQ_IsFull (CircularQueue* Queue) {
	if (Queue->Front < Queue->Rear) // 1F 2 3 4 5 6(real_Rear) R
		return (Queue->Rear - Queue->Front) == Queue->Capacity;
	else // 7 R 2F 3 4 5 6
		return (Queue->Rear + 1) == Queue->Front;
}

