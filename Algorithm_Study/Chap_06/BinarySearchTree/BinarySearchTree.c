#include "BinarySearchTree.h"

BSTNode* BST_CreateNode(ElementType NewData)
{
	BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;
	
	return NewNode;
}

void BST_DestroyNode(BSTNode* Node)
{
	free(Node);
}

void BST_DestroyTree(BSTNode* Tree)
{
	if(Tree->Right != NULL)
		BST_DestroyTree(Tree->Right);
	else if(Tree->Left != NULL)
		BST_DestroyTree(Tree->Left);
	
	Tree->Left = NULL;
	Tree->Right = NULL;
	
	BST_DestroyNode(Tree);
}


BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target)
{
	if(Tree == NULL)
		return NULL;
	
	if(Tree->Data == Target)
		return Tree;
	else if(Tree->Data > Target)
		BST_SearchNode(Tree->Left, Target);
	else
		BST_SearchNode(Tree->Right, Target);
}

BSTNode* BST_SearchMinNode(BSTNode* Tree)
{
	if(Tree == NULL)
		return NULL;
	
	if(Tree->Left == NULL)
		return Tree;
	else
		BST_SearchMinNode(Tree->Left);
}

void BST_InsertNode(BSTNode* Tree, BSTNode* Child)
{
	if(Tree->Data < Child->Data)
	{
		if(Tree->Right == NULL)
			Tree->Right = Child;
		else
			BST_InsertNode(Tree->Right, Child);
	}
	
	else if(Tree->Data > Child->Data)
	{
		if(Tree->Left == NULL)
			Tree->Left = Child;
		else
			BST_InsertNode(Tree->Left, Child);
	}
}

BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target)
{
	BSTNode* Removed = NULL;
	
	if(Tree == NULL)
		return NULL;
	
	if(Tree->Data > Target)
		Removed = BST_RemoveNode(Tree->Left, Tree, Target);
	else if(Tree->Data < Target)
		Removed = BST_RemoveNode(Tree->Right, Tree, Target);
	else // 목표값을 찾은 경우
	{
		Removed = Tree;
		
		// 잎 노드인 경우 바로 삭제
		if(Tree->Left == NULL && Tree->Right == NULL)
		{
			if(Parent->Left == Tree)
				Parent->Left = NULL;
			else
				Parent->Right = NULL;
		}
		
		else
		{
			if(Tree->Left != NULL && Tree->Right != NULL)
			{
				// 자식이 양쪽에 있는 경우
				BSTNode* MinNode = BST_SearchMinNode(Tree->Right);		// remove 대상 노드를 루트로 하는 트리에서 최솟값을 찾아 그 노드를 MinNode에 초기화.
				MinNode = BST_RemoveNode(Tree, NULL, MinNode->Data);	// 실제 트리에 존재하는 MinNode 데이터를 삭제하기 위함.
				Tree->Data = MinNode->Data;
			}
			else
			{
				// 자식이 한쪽에만 있는 경우
				BSTNode* Temp = NULL;
				if(Tree->Left != NULL)
					Temp = Tree->Left;
				else
					Temp = Tree->Right;
			
				if(Parent->Left == Tree)
					Parent->Left = Temp;
				else
					Parent->Right = Temp;
			}
		}
	}
	
	return Removed;		// 제거된 노드의 주소를 받아서 호출하는 쪽에서 해당 노드를 free하여 메모리를 해제할 수 있습니다.
}

void BST_InorderPrintTree(BSTNode* Node)
{
	if(Node == NULL)
		return ;
	
	// 왼쪽 하위 트리 출력
	BST_InorderPrintTree(Node->Left);
	
	// 뿌리 노드 출력
	printf("%d ", Node->Data);
	
	// 오른쪽 하위 트리 출력
	BST_InorderPrintTree(Node->Right);
}