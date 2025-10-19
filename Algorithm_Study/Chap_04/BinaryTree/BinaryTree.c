#include "BinaryTree.h"

SBTNode* SBT_CreateNode (ElementType NewData)
{
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	
	NewNode->Data = NewData;
	
	return NewNode;
}

void SBT_DestroyNode (SBTNode* Node)
{
	free (Node);
}

void SBT_DestroyTree (SBTNode* Root)
{
	if (Root == NULL)
		return;
	
	// 하위 왼쪽 트리 소멸
	SBT_DestroyTree (Root->Left);
	
	// 하위 오른쪽 트리 소멸
	SBT_DestroyTree (Root->Right);
	
	// 뿌리 노드 소멸
	SBT_DestroyNode (Root);
}

void SBT_PreorderPrintTree (SBTNode* Node)
{
	if (Node == NULL)
		return;
	
	// 전위 순회 (뿌리노드 -> 왼쪽 하위트리 -> 오른쪽 하위트리)
	printf (" %c", Node->Data);
	SBT_PreorderPrintTree (Node->Left);
	SBT_PreorderPrintTree (Node->Right);
}

void SBT_InorderPrintTree (SBTNode* Node)
{
	if (Node == NULL)
		return ;
	
	// 중위 순회 (왼쪽 하위트리 -> 뿌리 -> 오른쪽 하위트리)
	SBT_InorderPrintTree (Node->Left);
	printf (" %c", Node->Data);
	SBT_InorderPrintTree (Node->Right);
}

void SBT_PostorderPrintTree (SBTNode* Node) 
{
	if (Node == NULL)
		return ;
	
	// 후위순회 (왼쪽 하위트리 -> 오른쪽 하위트리 -> 뿌리노드)
	SBT_PostorderPrintTree (Node->Left);
	SBT_PostorderPrintTree (Node->Right);
	printf (" %c", Node->Data);
}