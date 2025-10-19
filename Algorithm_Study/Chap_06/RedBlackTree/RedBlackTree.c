#include "RedBlackTree.h"
#include <string.h>

extern RBTNode* Nil; // main.c에서 참조하는 키워드

RBTNode* RBT_CreateNode( ElementType NewData )
{
	RBTNode* NewNode = (RBTNode*)malloc(sizeof(RBTNode));
	NewNode->Parent = NULL;
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	
	NewNode->Data = NewData;
	NewNode->Color = BLACK;
	printf("Create %d\n", NewNode->Data);
	
	return NewNode;
}

void RBT_DestroyNode( RBTNode* Node )
{
	free(Node);
}

void RBT_DestroyTree( RBTNode* Tree )
{
	if(Tree == NULL)
		return;
	
	if( Tree->Right != Nil )
		RBT_DestroyTree(Tree->Right);
	
	if(Tree->Left != Nil)
		RBT_DestroyTree(Tree->Left);
	
	Tree->Left = Nil;
	Tree->Right = Nil;
	
	RBT_DestroyNode(Tree);
}



void RBT_RotateLeft( RBTNode** Root, RBTNode* Parent )
{
	RBTNode* RightChild = Parent->Right;
	
	Parent->Right = RightChild->Left;
	if(RightChild->Left != Nil)
		RightChild->Left->Parent = Parent;
	
	RightChild->Parent = Parent->Parent;
	
	if(Parent->Parent == NULL)
		(*Root) = RightChild;
	else
	{
		if(Parent == Parent->Parent->Left)
			Parent->Parent->Left = RightChild;
		else
			Parent->Parent->Right = RightChild;
	}
	
	RightChild->Left = Parent;
	Parent->Parent = RightChild;
}
void RBT_RotateRight( RBTNode** Root, RBTNode* Parent )
{
	RBTNode* LeftChild = Parent->Left;
	
	Parent->Left = LeftChild->Right;
	
	if(LeftChild->Right != Nil)
		LeftChild->Right->Parent = Parent;
	
	LeftChild->Parent = Parent->Parent;
	
	if(Parent->Parent == NULL)
		(*Root) = LeftChild;
	
	else
	{
		if(Parent == Parent->Parent->Left)
			Parent->Parent->Left = LeftChild;
		else
			Parent->Parent->Right = LeftChild;
	}
	
	LeftChild->Right = Parent;
	Parent->Parent = LeftChild;
}



RBTNode* RBT_SearchNode( RBTNode* Tree, ElementType Target )
{
	if(Tree == Nil)
		return NULL;
	
	if(Tree->Data > Target)
		return RBT_SearchNode(Tree->Left, Target);
	else if (Tree->Data < Target)
		return RBT_SearchNode(Tree->Right, Target);
	else
		return Tree;
}

RBTNode* RBT_SearchMinNode( RBTNode* Tree )
{
	if(Tree == Nil)
		return Nil;
	
	if(Tree->Left != Nil)
		return RBT_SearchMinNode(Tree->Left);
	else
		return Tree;
}



void RBT_InsertNodeHelper( RBTNode** Tree, RBTNode* NewNode )
{
	if((*Tree) == NULL)
		(*Tree) = NewNode;
	
	if( (*Tree)->Data < NewNode->Data )
	{
		if( (*Tree)->Right == Nil )
		{
			(*Tree)->Right = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
		{
			RBT_InsertNodeHelper( &(*Tree)->Right, NewNode );
		}
	}
	
	else if ( (*Tree)->Data > NewNode->Data )
	{
		if( (*Tree)->Left == Nil )
		{
			(*Tree)->Left = NewNode;
			NewNode->Parent = (*Tree);
		}
		else
			RBT_InsertNodeHelper( &(*Tree)->Left, NewNode );
	}
}

void RBT_InsertNode( RBTNode** Tree, RBTNode* NewNode )
{
	RBT_InsertNodeHelper( Tree, NewNode );
	
	NewNode->Color = RED;
	NewNode->Left = Nil;
	NewNode->Right = Nil;
	
	RBT_RebuildAfterInsert( Tree, NewNode );
}

void RBT_RebuildAfterInsert( RBTNode** Tree, RBTNode* NewNode )
{
	while(NewNode != (*Tree) && NewNode->Parent->Color == RED)
		// 레드 노드의 자식은 블랙 노드여야함
	{
		if(NewNode->Parent == NewNode->Parent->Parent->Left)
			// 부모 노드가 조부모 노드의 왼쪽 자식인 경우
		{
			RBTNode* Uncle = NewNode->Parent->Parent->Right;
			if(Uncle->Color == RED)
			{
				NewNode->Parent->Color = BLACK;
				Uncle->Color = BLACK;
				NewNode->Parent->Parent->Color = RED;
				
				NewNode = NewNode->Parent->Parent; // 문제되는 지점 타고 올라가기
			}
			else
			{
				if(NewNode == NewNode->Parent->Right)
				{
					NewNode = NewNode->Parent;
					RBT_RotateLeft(Tree, NewNode);
				}
				
				NewNode->Parent->Color = BLACK;
				NewNode->Parent->Parent->Color = RED;
				
				RBT_RotateRight(Tree, NewNode->Parent->Parent);
			}
		}
		else{
			// 부모가 조부모의 오른쪽 자식
			RBTNode* Uncle = NewNode->Parent->Parent->Left;
			if (Uncle->Color == RED)
			{
				NewNode->Parent->Parent->Color = BLACK;
				Uncle->Color = BLACK;
				NewNode->Parent->Parent->Color = RED;
				
				NewNode = NewNode->Parent->Parent;
			}
			else
			{
				if(NewNode == NewNode->Parent->Left)
				{
					NewNode = NewNode->Parent;
					RBT_RotateRight(Tree, NewNode);
				}
				
				NewNode->Parent->Color = BLACK;
				NewNode->Parent->Parent->Color = RED;
				RBT_RotateLeft(Tree, NewNode->Parent->Parent);
			}
		}
	}
	
	(*Tree)->Color = BLACK;
}



RBTNode* RBT_RemoveNode( RBTNode** Root, ElementType Data )
{
	RBTNode* Removed = NULL;
	RBTNode* Successor = NULL;
	RBTNode* Target = RBT_SearchNode((*Root), Data);
	
	if (Target == NULL)
		return NULL;
	
	if(Target->Left == Nil || Target->Right == Nil)
	{
		// 제거 대상의 양쪽 자식이 Nil 노드이면 바로 삭제.
		Removed = Target;
	}
	else
	{
		// 양쪽 노드가 모두 Nil이 아니라면 타겟 노드의 오른쪽 트리에서 가장 작은 노드를 찾아서
		// 타겟 노드의 데이터 값과 변경
		// 트리에서 제거되는 값은 Target노드의 데이터이지만, Target노드의 데이터는 그보다 더 작은 값으로 바꾸는 뿐
		// 바뀌는 대상 Removed가 트리에선 사라지는 것.
		Removed = RBT_SearchMinNode(Target->Right);
		Target->Data = Removed->Data;	
	}
	
	if( Removed->Left != Nil )
		Successor = Removed->Left; // 제거대상의 왼자식이 Nil이 아닌 경우, 이중 흑색 노드
	else
		Successor = Removed->Right; // 제거대상의 오른자식이 Nil이 아닌 경우, 이중 흑색 노드
	
	Successor->Parent = Removed->Parent; // 이중 흑색 노드를 제거 대상의 부모와 연결
	
	if(Removed->Parent == NULL)
		(*Root) = Successor;
	else
	{
		// 제거 대상의 부모를 이중 흑색 노드에 연결
		if(Removed == Removed->Parent->Left)
			Removed->Parent->Left = Successor;
		else
			Removed->Parent->Right = Successor;
	}
	
	if(Removed->Color == BLACK)
		RBT_RebuildAfterRemove(Root, Successor);
	
	return Removed;
}

void RBT_RebuildAfterRemove( RBTNode** Root, RBTNode* Successor )
{	// 이중 흑색 노드를 처리하는 네 가지 처리 과정을 담는 함수.
	// 매개변수 Successor, 즉 대체 노드가 이중 흑색 노드
	// Successor 위에 검은색이 하나 더 있다고 생각하기
	RBTNode* Sibling = NULL; // 이중 흑색 노드의 형제 노드
	
	while( Successor->Parent != NULL && Successor->Color == BLACK)
		// 뿌리 노드이거나 빨간색 노드로 검은색이 넘어가면 루프 종료
	{
		if(Successor == Successor->Parent->Left)
		{	// 이중 흑색 노드가 왼 자식인 경우
			Sibling = Successor->Parent->Right;
			
			if(Sibling->Color == RED)
			{
				Sibling->Color = BLACK;
				Successor->Parent->Color = RED;
				RBT_RotateLeft(Root, Successor->Parent);
			}
			else
			{
				if(Sibling->Left->Color == BLACK && Sibling->Right->Color == BLACK)
				{
					Sibling->Color = RED;
					
					RBT_RotateRight(Root, Sibling);
					Sibling = Successor->Parent->Right;
				}
				
				Sibling->Color = Successor->Parent->Color;
				Successor->Parent->Color = BLACK;
				Sibling->Right->Color = BLACK;
				RBT_RotateLeft(Root, Successor->Parent);
				Successor = (*Root);
			}
		}
		else
		{	// 이중 흑색 노드가 오른 자식인 경우
			Sibling = Successor->Parent->Left;
			
			if(Sibling->Color == RED)
			{
				Sibling->Color = BLACK;
				Successor->Parent->Color = RED;
				RBT_RotateRight(Root, Successor->Parent);
			}
			else
			{
				if(Sibling->Right->Color == BLACK && Sibling->Left->Color == BLACK)
				{
					Sibling->Color = RED;
					Successor = Successor->Parent;
				}
				else
				{
					if(Sibling->Right->Color == RED)
					{
						Sibling->Right->Color = BLACK;
						Sibling->Color = RED;
						
						RBT_RotateLeft(Root, Sibling);
						Sibling = Successor->Parent->Left;
					}
					
					Sibling->Color = Successor->Parent->Color;
					Successor->Parent->Color = BLACK;
					Sibling->Left->Color = BLACK;
					RBT_RotateRight(Root, Successor->Parent);
					Successor = (*Root);
				}
			}
		}
	}
	
	Successor->Color = BLACK;
}



void RBT_PrintTree( RBTNode* Node, int Depth, int BlackCount )
{
	int i=0;
	char c = 'X';
	int v = -1;
	char cnt[100];
	
	if(Node == NULL || Node == Nil)
		return;
	
	if(Node->Color == BLACK)
		BlackCount++;
	
	if(Node->Parent != NULL)
	{
		v = Node->Parent->Data;
		
		if(Node->Parent->Left == Node)
			c = 'L';
		else
			c = 'R';
	}
	
	if (Node->Left == Nil && Node->Right == Nil)
		sprintf(cnt, "------- %d", BlackCount);
	else
		strncpy(cnt, "", sizeof(cnt));
	
	for(i=0; i<Depth; i++)
		printf(" ");
	
	printf(" %d %s [%c, %d] %s\n", Node->Data, (Node->Color == RED) ? "RED" : "BLACK", c, v, cnt);
	
	RBT_PrintTree(Node->Left, Depth+1, BlackCount);
	RBT_PrintTree(Node->Right, Depth+1, BlackCount);
}