#include "ShortestPath.h"

void Dijkstra (Graph* G, Vertex* StartVertex, Graph* ShortestPath)
{
	int i=0;
	
	PQNode StartNode = {0, StartVertex};
	PriorityQueue* PQ = PQ_Create(10);
	
	Vertex* CurrentVertex = NULL;
	Edge* CurrentEdge = NULL;
	
	int* Weights = 			(int*) malloc (sizeof(int) * G->VertexCount);
	
	Vertex** ShortestPathVertices = 
							(Vertex**) malloc (sizeof(Vertex*) * G->VertexCount);

	// 아직 트리에 포함되지는 않았지만, 이미 트리에 속한 정점들과 직접 연결된 정점들을 가리킵니다. 
	// 알고리즘은 이 '경계'에 있는 정점들 중에서 가장 가중치가 낮은 간선을 선택하여 트리를 확장해 나갑니다.
	Vertex** Fringes = 		(Vertex**) malloc (sizeof(Vertex*) * G->VertexCount);

	// 각 정점이 MST에 포함될 때, 그 정점을 MST에 연결시켜준 선행(preceding) 정점이 무엇인지를 기록합니다. 
	// 이 배열은 알고리즘 실행이 끝난 후 MST의 최종적인 구조(어떤 정점들이 어떤 간선으로 연결되어 있는지)를 재구성하는 데 사용됩니다.
	Vertex** Precedences =  (Vertex**) malloc (sizeof(Vertex*) * G->VertexCount);
	
	CurrentVertex = G->Vertices;
	while (CurrentVertex != NULL)
	{
		Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
		AddVertex (ShortestPath, NewVertex);
		
		Fringes[i] = NULL;
		Precedences[i] = NULL;
		ShortestPathVertices[i] = NewVertex;
		Weights[i] = MAX_WEIGHT;
		
		CurrentVertex = CurrentVertex->Next;
		i++;
	}
	
	PQ_Enqueue (PQ, StartNode);
	Weights[StartVertex->Index] = 0;
	
	while ( ! PQ_IsEmpty(PQ) )
	{
		PQNode Popped;
		PQ_Dequeue(PQ, &Popped);
		CurrentVertex = (Vertex*)Popped.Data;
		
		Fringes[CurrentVertex->Index] = CurrentVertex;
		
		CurrentEdge = CurrentVertex->AdjacencyList;
		
		while(CurrentEdge != NULL)
		{
			Vertex* TargetVertex = CurrentEdge->Target;
			
			if(Fringes[TargetVertex->Index] == NULL &&
			   Weights[CurrentVertex->Index] + CurrentEdge->Weight < 
			  									Weights[TargetVertex->Index])
			{
				PQNode NewNode = {CurrentEdge->Weight, TargetVertex};
				PQ_Enqueue(PQ, NewNode);
				
				Precedences[TargetVertex->Index] = CurrentEdge->From;
				Weights[TargetVertex->Index] = 
							Weights[CurrentVertex->Index] + CurrentEdge->Weight;
			}
			
			CurrentEdge = CurrentEdge->Next;
		}
	}
	
	for (i=0; i<G->VertexCount; i++)
	{
		int FromIndex, ToIndex;
		
		if (Precedences[i] == NULL)
			continue;
		
		FromIndex = Precedences[i]->Index;
		ToIndex = i;
		
		AddEdge(ShortestPathVertices[FromIndex],
			   	CreateEdge (
						ShortestPathVertices[FromIndex],
						ShortestPathVertices[ToIndex],
						Weights[i] ) );
	}
	
	free(Fringes);
	free(Precedences);
	free(Weights);
	free(ShortestPathVertices);
	
	PQ_Destroy(PQ);
}