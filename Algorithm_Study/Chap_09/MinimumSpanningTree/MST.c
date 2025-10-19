#include "MST.h"

void Prim (Graph* G, Vertex* StartVertex, Graph* MST)
{
	int i=0;
	
	PQNode StartNode = {0, StartVertex};
	PriorityQueue* PQ = PQ_Create(10);
	
	Vertex* CurrentVertex = NULL;
	Edge* CurrentEdge = NULL;
	
	// 각 정점까지의 "최소 가중치"를 저장하는 배열
	int* Weights = (int*)malloc(sizeof(int) * G->VertexCount);	
	
	// 최종 MST를 구성할 정점들을 담을 배열
	Vertex** MSTVertices = (Vertex**)malloc (sizeof(Vertex*) * G->VertexCount);
	
	// 아직 트리에 포함되지는 않았지만, 이미 트리에 속한 정점들과 직접 연결된 정점들을 가리킵니다. 
	// 알고리즘은 이 '경계'에 있는 정점들 중에서 가장 가중치가 낮은 간선을 선택하여 트리를 확장해 나갑니다.
	Vertex** Fringes = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
	
	// 각 정점이 MST에 포함될 때, 그 정점을 MST에 연결시켜준 선행(preceding) 정점이 무엇인지를 기록합니다. 
	// 이 배열은 알고리즘 실행이 끝난 후 MST의 최종적인 구조(어떤 정점들이 어떤 간선으로 연결되어 있는지)를 재구성하는 데 사용됩니다.
	Vertex** Precedences = (Vertex**)malloc (sizeof(Vertex*) * G->VertexCount);		
	
	CurrentVertex = G->Vertices;
	while(CurrentVertex != NULL)
	{
		Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
		AddVertex(MST, NewVertex);
		
		Fringes[i] = NULL;
		Precedences[i] = NULL;
		MSTVertices[i] = NewVertex; // Index를 이용해 MST의 특정 정점에 빠르게 접근하기 위한 색인(Index) 역할을 할 뿐입니다.
		Weights[i] = MAX_WEIGHT;
		CurrentVertex = CurrentVertex->Next;
		
		i++;
	}
	
	PQ_Enqueue(PQ, StartNode);
	
	Weights[StartVertex->Index] = 0;
	
	while(!PQ_IsEmpty(PQ))
	{
		PQNode Popped;
		
		PQ_Dequeue(PQ, &Popped);					// 우선순위 큐에서 가장 작은 가중치를 가진 PQNode를 꺼냅니다.
		CurrentVertex = (Vertex*)Popped.Data;		// CurrentVertex는 현재 MST에 추가될 새로운 정점
		
		Fringes[CurrentVertex->Index] = CurrentVertex;	// 이 정점이 이제 MST에 '포함되었음'을 표시
		
		CurrentEdge = CurrentVertex->AdjacencyList;		// CurrentVertex의 인접 리스트(AdjacencyList)를 순회
		
		while(CurrentEdge != NULL)
		{
			Vertex* TargetVertex = CurrentEdge->Target;	// Fringes 배열에 있는, 즉 포함 된 정점의 인접 정점을 타깃 정점으로 삼는다.
			
			// TargetVertex가 아직 MST에 포함되지 않았는지 확인
			// CurrentVertex에서 TargetVertex로 가는 간선의 가중치가 TargetVertex에 현재 저장된 가중치(Weights 배열)보다 작은지 확인
			
			// 조건을 모두 만족하면, TargetVertex로 가는 더 짧은 경로를 찾은 것이므로 
			// 우선순위 큐에 NewNode를 추가하고 Precedences와 Weights 배열을 업데이트.
			
			if(Fringes[TargetVertex->Index] == NULL &&
			  CurrentEdge->Weight < Weights[TargetVertex->Index])
			{
				PQNode NewNode = {CurrentEdge->Weight, TargetVertex};
				PQ_Enqueue(PQ, NewNode);
				
				// Precedences[Target->Index]에 현재 정점을 기록하여, 나중에 이 간선이 MST의 일부임을 나타냅니다.
				Precedences[TargetVertex->Index] = CurrentEdge->From;	// TargetVertex의 부모 노드가 저장.
				Weights[TargetVertex->Index] = CurrentEdge->Weight;
			}
			
			CurrentEdge = CurrentEdge->Next;
		}
	}
	
	// for 루프를 통해 Precedences 배열을 순회
	for(i=0; i<G->VertexCount; i++)
	{
		int FromIndex, ToIndex;
		
		 // 1. Precedences 배열을 순회하며 간선 정보를 확인합니다.
		if(Precedences[i] == NULL)
			continue;
		
		// 2. Precedences 배열에 기록된 부모-자식 관계를 읽어옵니다.
		FromIndex = Precedences[i]->Index;		// 부모 정점의 인덱스
		ToIndex = i;							// 자식 정점의 인덱스
		
		
		// 3. MST에 간선을 추가합니다.
		// 1단계에서 MSTVertices 배열에 저장해 둔 포인터를 사용해
    	// MST에 직접 간선(Edge)을 추가합니다.
		// AddEdge 함수를 사용하여 이 부모-자식 관계에 해당하는 간선을 MST 그래프에 추가
		AddEdge(MSTVertices[FromIndex],
			   CreateEdge(MSTVertices[FromIndex], MSTVertices[ToIndex], Weights[i]));
		
		// 4. 무방향 그래프이므로 반대 방향 간선도 추가합니다.
		AddEdge(MSTVertices[ToIndex],
			   CreateEdge(MSTVertices[ToIndex], MSTVertices[FromIndex], Weights[i]));
	}
	
	free(Fringes);
	free(Precedences);
	free(MSTVertices);
	free(Weights);
	
	free(PQ);
}

void Kruskal (Graph* G, Graph* MST)
{
	int i=0;
	Vertex* CurrentVertex = NULL;
	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
	DisjointSet** VertexSet = (DisjointSet**)malloc(sizeof(DisjointSet*) * G->VertexCount);
	
	PriorityQueue* PQ = PQ_Create(10);
	
	CurrentVertex = G->Vertices;
	
	while (CurrentVertex != NULL)
	{
		Edge* CurrentEdge;
		
		VertexSet[i] = DS_MakeSet(CurrentVertex);
		MSTVertices[i] = CreateVertex(CurrentVertex->Data);
		AddVertex(MST, MSTVertices[i]);
		
		CurrentEdge = CurrentVertex->AdjacencyList;
		
		while (CurrentEdge != NULL)
		{
			PQNode NewNode = {CurrentEdge->Weight, CurrentEdge};
			PQ_Enqueue(PQ, NewNode);
			
			CurrentEdge = CurrentEdge->Next;
		}
		
		CurrentVertex = CurrentVertex->Next;
		i++;
	}
	
	while ( !PQ_IsEmpty(PQ) )
	{
		Edge* CurrentEdge;
		int FromIndex;
		int ToIndex;
		PQNode Popped;
		
		PQ_Dequeue(PQ, &Popped);
		CurrentEdge = (Edge*)Popped.Data;
		
		printf("%c - %c : %d\n",
			  CurrentEdge->From->Data,
			  CurrentEdge->Target->Data,
			  CurrentEdge->Weight);
		
		FromIndex = CurrentEdge->From->Index;
		ToIndex = CurrentEdge->Target->Index;
		
		if(DS_FindSet(VertexSet[FromIndex]) != DS_FindSet(VertexSet[ToIndex]))
		{
			AddEdge (MSTVertices[FromIndex],
					CreateEdge(MSTVertices[FromIndex],
							  MSTVertices[ToIndex],
							  CurrentEdge->Weight ));
			
			AddEdge (MSTVertices[ToIndex],
					CreateEdge(MSTVertices[ToIndex],
							  MSTVertices[FromIndex],
							  CurrentEdge->Weight ));
			
			DS_UnionSet(VertexSet[FromIndex], VertexSet[ToIndex]);
		}
	}
	
	for(i=0; i<G->VertexCount; i++)
		DS_DestroySet(VertexSet[i]);
	
	free(VertexSet);
	free(MSTVertices);
}