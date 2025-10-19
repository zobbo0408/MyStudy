#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// enum을 구조체 밖으로 빼서 전역적으로 유효하게 만듭니다.
typedef enum tagRBTColor
{
    RED,
    BLACK
} RBTColor; // RBTColor 라는 새로운 타입 이름을 정의합니다.

typedef struct tagRBTNode
{
	struct tagRBTNode* Parent;
	struct tagRBTNode* Left;
	struct tagRBTNode* Right;
	
	RBTColor Color; // 이제 Color 멤버는 RBTColor 타입이 됩니다.
	ElementType Data;
} RBTNode;

// typedef struct tagRBTNode
// {
// 	struct tagRBTNode* Parent;
// 	struct tagRBTNode* Left;
// 	struct tagRBTNode* Right;
	
// 	enum {RED, BLACK} Color;
// 	ElementType Data;
// } RBTNode;

RBTNode* RBT_CreateNode( ElementType NewData );
void RBT_DestroyNode( RBTNode* Node );
void RBT_DestroyTree( RBTNode* Tree );

RBTNode* RBT_SearchNode( RBTNode* Tree, ElementType Target );
RBTNode* RBT_SearchMinNode( RBTNode* Tree );

void RBT_InsertNode( RBTNode** Tree, RBTNode* NewNode );
void RBT_InsertNodeHelper( RBTNode** Tree, RBTNode* NewNode );

RBTNode* RBT_RemoveNode( RBTNode** Root, ElementType Data );

void RBT_RebuildAfterInsert( RBTNode** Tree, RBTNode* NewNode );
void RBT_RebuildAfterRemove( RBTNode** Root, RBTNode* X );

void RBT_PrintTree( RBTNode* Node, int Depth, int BlackCount );
void RBT_RotateLeft( RBTNode** Root, RBTNode* Parent );
void RBT_RotateRight( RBTNode** Root, RBTNode* Parent );

#endif