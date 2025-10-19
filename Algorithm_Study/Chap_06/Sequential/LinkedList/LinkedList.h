#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
	ElementType Data;
	int Count;
	struct tagNode* NextNode;
} Node;

Node* SLL_CreateNode(ElementType NewData);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
void SLL_InsertAfter(Node* Current, Node* NewNode);
void SLL_InsertNewHead(Node** Head, Node* NewNode);
void SLL_RemoveNode(Node** Head, Node* Remove);
Node* SLL_GetNodeAt(Node* Head, int Location);
int SLL_GetNodeCount(Node* Head);
Node* SLL_SequentialSearch(Node* Head, int Target);
Node* SLL_MoveToFront(Node** Head, int Target);
Node* SLL_Transpose(Node** Head, int Target);
Node* SLL_FrequencyCount(Node** Head, int Target);

#endif