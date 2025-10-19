#include "Calculator.h"

char NUMBER[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};

int IsNumber (char Cipher){
	// 해당 문자가 숫자 또는 .인지 확인
	int i=0;
	int ArrayLength = sizeof(NUMBER);
	
	for(i=0; i<ArrayLength; i++) {
		if(Cipher == NUMBER[i])
			return 1;
	}
	
	return 0;
}

unsigned int GetNextToken (char* Expression, char* Token, int* Type) {
	unsigned int i=0;
	
	// 표현식의 각 값들의 타입을 지정
	for (i=0; 0!=Expression[i]; i++) {
		// 널 문자(\0)가 아닐 때까지 반복하라는 의미
		
		Token[i] = Expression[i];
		
		if(IsNumber(Expression[i]) == 1) {
			*Type = OPERAND; // 토큰이 피연산자라면 Type 변수값을 OPERAND(피연산자)로 초기화
			
			if (IsNumber(Expression[i+1]) != 1)
				// 피연산자 이후 연산자가 나오면 브레이크
				break;
		}
		
		else {
			*Type = Expression[i]; // 토큰 타입을 현재 문자의 ASCII 값으로 설정
			break;
		}
	}
	
	Token[++i] = '\0';
	return i; // 토큰의 길이 리턴
}

// 우선순위 지정
int GetPriority (char Operator, int InStack) {
	int Priority = -1;
	
	switch(Operator) {
		case LEFT_PARENTHESIS:	
			if (InStack) 
				Priority = 3;	// (3순위 - )
			else
				Priority = 0;	// (0순위 - Token)
			break;
			
		case MULTIPLY:	// (1순위)
		
		case DIVIDE:	// (1순위)
			Priority = 1;
			break;
			
		case PLUS :		// (2순위)
			
		case MINUS:		// (2순위)
			Priority = 2;
			break;
	}
	
	return Priority;
}

int IsPrior (char Operator1, char Operator2) {
	// Operator1 이 Top, Operator2 가 Token
	return (GetPriority(Operator1, 1) > GetPriority(Operator2, 0));
}

void GetPostfix (char* InfixExpression, char* PostfixExpression) { 
	LinkedListStack* Stack;
	
	char Token[32]; // 표현식의 최소 단위, 8 바이트
	int Type = -1;
	unsigned int Position = 0;
	unsigned int Length = strlen(InfixExpression);
	
	LLS_CreateStack(&Stack); // 스택 생성
	
	while (Position < Length) {
		Position += GetNextToken(&InfixExpression[Position], Token, &Type); // 토큰의 각 값들의 타입을 지정
		
		if(Type == OPERAND) {
			strcat(PostfixExpression, Token);
			strcat(PostfixExpression, " ");
		}
		else if (Type == RIGHT_PARENTHESIS) {
			while (!LLS_IsEmpty(Stack)) {
				Node* Popped = LLS_Pop(Stack);
				
				if(Popped->Data[0] == LEFT_PARENTHESIS) {
					LLS_DestroyNode(Popped);
					break;
				}
				else {
					strcat(PostfixExpression, Popped->Data);
					LLS_DestroyNode(Popped);
				}
			}
		}
		else {
			while (!LLS_IsEmpty(Stack) && !IsPrior(LLS_Top(Stack)->Data[0], Token[0])) { 	//!IsPrior(LLS_Top(Stack)->Data[0], Token[0]) - 스택이 토큰보다 우선순위가 높은 경우
				Node* Popped = LLS_Pop(Stack);
				
				if(Popped->Data[0] != LEFT_PARENTHESIS) 
					strcat(PostfixExpression, Popped->Data);
				
				LLS_DestroyNode(Popped);
			}
			// +의 경우 스택이 비어서 바로 푸쉬, 토큰이 우선순위가 높으면 바로 푸쉬
			// 만일 스택의 Top이 토큰보다 우선순위가 높은 경우 else문 작동
			LLS_Push(Stack, LLS_CreateNode(Token));
		}
	}
	
	while (!LLS_IsEmpty(Stack)) {
		Node* Popped = LLS_Pop(Stack);
		
		if(Popped->Data[0] != LEFT_PARENTHESIS)
			strcat(PostfixExpression, Popped->Data);
		
		LLS_DestroyNode(Popped);
	}
	
	LLS_DestroyStack(Stack);
}

double Calculate (char* PostfixExpression) {
	LinkedListStack* Stack;
	Node* ResultNode;
	
	double Result;
	char Token[32];
	int Type = -1;
	unsigned int Read = 0;
	unsigned int Length = strlen(PostfixExpression);
	
	LLS_CreateStack(&Stack);
	
	while (Read < Length) {
		Read += GetNextToken(&PostfixExpression[Read], Token, &Type);
		if (Type == SPACE)
			continue;
		
		if(Type == OPERAND){
			Node* NewNode = LLS_CreateNode(Token);
			LLS_Push(Stack, NewNode);
		}
		else {
			char ResultString[32];
			double Operator1, Operator2, TempResult;
			Node* OperatorNode;
			
			OperatorNode = LLS_Pop(Stack);
			Operator2 = atof(OperatorNode->Data);
			LLS_DestroyNode(OperatorNode);
			
			OperatorNode = LLS_Pop(Stack);
			Operator1 = atof(OperatorNode->Data);
			LLS_DestroyNode(OperatorNode);
			
			switch(Type) {
				case PLUS:	TempResult = Operator1 + Operator2; break;
				case MINUS:	TempResult = Operator1 - Operator2; break;
				case MULTIPLY:	TempResult = Operator1 * Operator2; break;
				case DIVIDE:	TempResult = Operator1 / Operator2; break;
			}
			
			gcvt(TempResult, 10, ResultString); // 소수로 되어 있는 계산 결과를 문자열로 변환
			LLS_Push(Stack, LLS_CreateNode(ResultString));
		}
	}
	
	ResultNode = LLS_Pop(Stack);
	Result = atof(ResultNode->Data);
	
	LLS_DestroyNode(ResultNode);
	
	LLS_DestroyStack(Stack);
	
	return Result;
}