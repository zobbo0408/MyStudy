#include "ExpressionTree.h"

ETNode* ET_CreateNode(ElementType NewData)
{
	ETNode* NewNode = (ETNode*)malloc(sizeof(ETNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;
	
	return NewNode;
}

void ET_DestroyNode(ETNode* Node)
{
	free(Node);	
}

void ET_DestroyTree(ETNode* Root)
{
	if(Root == NULL)
		return ;
	ET_DestroyNode(Root->Left);
	ET_DestroyNode(Root->Right);
	ET_DestroyNode(Root);
}

void ET_PreorderPrintTree(ETNode* Node)
{
	if(Node == NULL)
		return ;
	
	printf(" %c ", Node->Data);
	ET_PreorderPrintTree(Node->Left);
	ET_PreorderPrintTree(Node->Right);
}

void ET_InorderPrintTree(ETNode* Node)
{
	if(Node == NULL)
		return ;
	
	printf("(");
	ET_InorderPrintTree(Node->Left);
	printf(" %c ", Node->Data);
	ET_InorderPrintTree(Node->Right);
	printf(")");
}

void ET_PostorderPrintTree(ETNode* Node)
{
	if(Node == NULL)
		return ;
	
	ET_PostorderPrintTree(Node->Left);
	ET_PostorderPrintTree(Node->Right);
	printf(" %c ", Node->Data);
}

void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node) // 맨 처음 노드는 널 형태 -> 노드를 변환해서 초기화 후 쭉 내려가는 형태
{
	int len = strlen(PostfixExpression);
	char Token = PostfixExpression[len-1];
	PostfixExpression[len-1] = '\0'; // 토큰으로 취한 자리는 널문자 처리
	
	switch(Token){
		case '+': case '-': case '*': case '/':
			(*Node) = ET_CreateNode(Token);
			ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right); // 재귀로 각 수식을 노드로 변환 후 오른쪽 먼저 하위 노드로 빌드
			ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
			break;
	
		default :
			(*Node) = ET_CreateNode(Token);
			break;
	}
}

double ET_Calculate(ETNode* Tree)
{
	char Temp[2];
	double Left = 0;
	double Right = 0;
	double Result = 0;
	
	if ( Tree == NULL )
		return 0;
	
	switch (Tree->Data){
		case '+': case '-': case '*': case '/':
			Left = ET_Calculate(Tree->Left);
			Right = ET_Calculate(Tree->Right);
			
			if(Tree->Data == '+')	Result = Left+Right;
			else if(Tree->Data == '-') Result = Left-Right;
			else if(Tree->Data == '*') Result = Left*Right;
			else if(Tree->Data == '/') Result = Left/Right;
			
			break;
		
		default:	// 리프 노드 -> 실수로 변환해서 반환 (재귀로 밑으로 타고 옴)
			memset(Temp, 0, sizeof(Temp));
			Temp[0] = Tree->Data;
			Result = atof(Temp);
			break;
	}
	
	return Result;
}