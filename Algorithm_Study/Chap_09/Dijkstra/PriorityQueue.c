#include "PriorityQueue.h"

PriorityQueue* PQ_Create ( int InitialSize )
{
	PriorityQueue* NewPQ = ( PriorityQueue* )malloc( sizeof( PriorityQueue ) );
	NewPQ->Capacity = InitialSize;
	NewPQ->UsedSize = 0;
	NewPQ->Nodes = ( PQNode* )malloc( sizeof( PQNode ) * NewPQ->Capacity );
	
	return NewPQ;
}

void PQ_Destroy ( PriorityQueue* PQ )
{
	free ( PQ->Nodes );
	free ( PQ );
}

void PQ_Enqueue ( PriorityQueue* PQ, PQNode NewData)
{
	int CurrentPosition = PQ->UsedSize;
	int ParentPosition = PQ_GetParent(CurrentPosition);
	
	if( PQ->UsedSize == PQ->Capacity )
	{
		if( PQ->Capacity == 0 )
			PQ->Capacity = 1;
		
		PQ->Capacity *= 2;
		PQ->Nodes = (PQNode*)realloc( PQ->Nodes, sizeof(PQNode)*PQ->Capacity );
	}
	
	PQ->Nodes[CurrentPosition] = NewData;
	// printf("작업명 : %s (우선순위:%d)\n", PQ->Nodes[CurrentPosition].Data, PQ->Nodes[CurrentPosition].Priority);
	
	// 후속 처리
	while ( CurrentPosition > 0 && PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority )
	{
		PQ_SwapNodes( PQ, CurrentPosition, ParentPosition );
		
		CurrentPosition = ParentPosition;
		ParentPosition = PQ_GetParent( CurrentPosition );
	}
	
	PQ->UsedSize ++ ;
}

// void PQ_Dequeue ( PriorityQueue* PQ, PQNode* Popped )
// {
// 	int ParentPosition = 0;
// 	int LeftPosition = 0;
// 	int RightPosition = 0;
	
// 	memcpy(Popped, &PQ->Nodes[0], sizeof(PQNode));
// 	memset(&PQ->Nodes[0], 0, sizeof(PQNode));		// PQ->Nodes 배열의 첫 번째 요소를 0으로 초기화(또는 비우는) 역할
	
// 	PQ->UsedSize--;
// 	PQ_SwapNodes(PQ, 0, PQ->UsedSize);
	
// 	LeftPosition = PQ_GetLeftChild(0);
// 	RightPosition = LeftPosition + 1;
	
// 	while (1)
// 	{
// 		int SelectedChild = 0;
		
// 		if(LeftPosition > PQ->UsedSize)
// 			break; // leaf
		
// 		if(RightPosition >= PQ->UsedSize)
// 		{
// 			SelectedChild = LeftPosition;
// 		}
// 		else
// 		{
// 			if(PQ->Nodes[LeftPosition].Priority > PQ->Nodes[RightPosition].Priority)
// 				SelectedChild = RightPosition;
// 			else
// 				SelectedChild = LeftPosition;
// 		}
		
// 		if( PQ->Nodes[SelectedChild].Priority < PQ->Nodes[ParentPosition].Priority )
// 		{
// 			PQ_SwapNodes(PQ, ParentPosition, SelectedChild);
// 			ParentPosition = SelectedChild;
// 		}
// 		else
// 			break;
		
// 		LeftPosition = PQ_GetLeftChild(ParentPosition);
// 		RightPosition = LeftPosition + 1;
// 	}
	
// 	if(PQ->UsedSize < (PQ->Capacity) / 2)
// 	{
// 		PQ->Capacity /= 2;
// 		PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
// 	}
// }

void PQ_Dequeue ( PriorityQueue* PQ, PQNode* Popped )
{
    // 큐가 비어있으면 아무것도 하지 않음 (선택적으로 에러 처리 추가 가능)
    if (PQ_IsEmpty(PQ)) {
        return;
    }

    // 1. 루트 노드의 데이터를 Popped에 복사
    memcpy(Popped, &PQ->Nodes[0], sizeof(PQNode));

    // 2. 힙의 마지막 노드를 루트 위치(0)로 이동시키고, UsedSize 감소
    //    이 시점에서 PQ->UsedSize-1은 현재 힙의 마지막 유효한 요소의 인덱스입니다.
    PQ_SwapNodes(PQ, 0, PQ->UsedSize-1);
    PQ->UsedSize--;

    // 3. 힙 재정렬 (Heapify Down) 시작
    int ParentPosition = 0; // 루트에서 시작
    while (1)
    {
        int LeftChildPosition = PQ_GetLeftChild(ParentPosition);
        int RightChildPosition = LeftChildPosition + 1;
        int SelectedChildPosition = -1; // 선택된 자식의 인덱스

        // 자식이 없는 경우 (리프 노드이거나 유효한 자식이 없음)
        if (LeftChildPosition >= PQ->UsedSize) {
            break; // 더 이상 자식이 없으므로 종료
        }
        // 왼쪽 자식만 있는 경우
        else if (RightChildPosition >= PQ->UsedSize) {
            SelectedChildPosition = LeftChildPosition;
        }
        // 왼쪽, 오른쪽 자식 모두 있는 경우
        else {
            if (PQ->Nodes[LeftChildPosition].Priority < PQ->Nodes[RightChildPosition].Priority)
                SelectedChildPosition = LeftChildPosition; // 왼쪽 자식이 더 작으면 왼쪽 선택
			else 
                SelectedChildPosition = RightChildPosition; // 오른쪽 자식이 더 작거나 같으면 오른쪽 선택
        }

        // 선택된 자식의 우선순위와 부모의 우선순위 비교
        if (PQ->Nodes[SelectedChildPosition].Priority < PQ->Nodes[ParentPosition].Priority) {
            PQ_SwapNodes(PQ, ParentPosition, SelectedChildPosition);
            ParentPosition = SelectedChildPosition; // 부모 위치를 선택된 자식 위치로 업데이트
        } 
		else {
            break; // 힙 속성을 만족하므로 종료
        }
    }

    // 4. 용량 축소 (옵션)
    // 힙의 크기가 Capacity의 절반보다 작아지고, Capacity가 최소 2 이상일 경우 용량 축소
    // UsedSize가 0이 되어 Capacity가 0이 되는 것을 방지하기 위해 Capacity > 1 조건 추가
    if (PQ->UsedSize > 0 && PQ->UsedSize < PQ->Capacity / 2)
    {
        if (PQ->Capacity > 1) { // Capacity가 0이 되는 것을 방지
            PQ->Capacity /= 2;
            PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
        }
    } else if (PQ->UsedSize == 0 && PQ->Capacity > 1) { // 큐가 비고 용량이 1보다 큰 경우
        PQ->Capacity = 1; // 최소 용량으로 줄임
        PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
    }
}

int PQ_GetParent ( int Index )
{
	return (int)(Index - 1) / 2;
}

int PQ_GetLeftChild ( int Index )
{
	return Index * 2 + 1;
}

void PQ_SwapNodes ( PriorityQueue* PQ, int Index1, int Index2 )
{
	int CopySize = sizeof( PQNode );
	PQNode* Temp = (PQNode*)malloc(CopySize);
	
	memcpy( Temp, &PQ->Nodes[Index1], CopySize );
	memcpy( &PQ->Nodes[Index1], &PQ->Nodes[Index2], CopySize );
	memcpy( &PQ->Nodes[Index2], Temp, CopySize );
	
	free ( Temp );
}

int PQ_IsEmpty ( PriorityQueue* PQ )
{
	return (PQ->UsedSize == 0);
}