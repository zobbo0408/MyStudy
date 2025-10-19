#ifndef GRAPH_TRAVERSAL_H
#define GRAPH_TRAVERSAL_H

#include "Graph.h"
#include "LinkedQueue.h"

void DFS( Vertex* V );						// 깊이 우선 탐색
void BFS( Vertex* V, LinkedQueue* Queue );	// 너비 우선 탐색

#endif