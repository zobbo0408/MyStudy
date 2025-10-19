#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode( ElementType NewData ) {
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->Data = NewData;
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	
	return NewNode;
}

void LCRS_DestroyNode (LCRSNode* Node) {
	free(Node);
}

void LCRS_DestroyTree (LCRSNode* Root){
	if(Root->RightSibling != NULL)
		LCRS_DestroyTree(Root->RightSibling);
	
	if(Root->LeftChild != NULL)
		LCRS_DestroyTree(Root->LeftChild);
	
	Root->LeftChild = NULL;
	Root->RightSibling = NULL;
	
	LCRS_DestroyNode(Root);
}


void LCRS_AddChildNode (LCRSNode* ParantNode, LCRSNode* ChildNode) {
	if (ParantNode->LeftChild == NULL)
		ParantNode->LeftChild = ChildNode;
	else {
		LCRSNode* TempNode = ParantNode->LeftChild;
		while(TempNode->RightSibling != NULL)
			TempNode = TempNode->RightSibling;
		
		TempNode->RightSibling = ChildNode;
	}
}

void LCRS_PrintNode (LCRSNode* Node, int Depth) {
	// 들여쓰기 방법
	int i=0;
	for (i=0; i<Depth-1; i++)
		printf("   "); // 공백 3칸
	if (Depth > 0) // 자식 노드 여부 확인
		printf("+--");
	
	//노드 데이터 출력
	printf("%c\n", Node->Data);
	
	if(Node->LeftChild != NULL)
		LCRS_PrintNode(Node->LeftChild, Depth+1);
	
	if(Node->RightSibling != NULL)
		LCRS_PrintNode(Node->RightSibling, Depth);
}