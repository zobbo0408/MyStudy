#include <stdio.h>
#include <stdlib.h>
#include "Calculator.h"

int main() {
	char InfixExpression[100];
	char PostfixExpression[100];
	
	double Result = 0;
	
	memset(InfixExpression, 0, sizeof(InfixExpression)); // InfixExpression 배열의 크기만큼 값을 모두 0으로 초기화.
	memset(PostfixExpression, 0, sizeof(PostfixExpression)); // PostfixExpression 배열의 크기만큼 값을 모두 0으로 초기화.
	
	printf("Enter Infix Expression : ");
	scanf("%s", InfixExpression);
	
	// 중위 표기식을 후위 표기식으로 변환.
	GetPostfix (InfixExpression, PostfixExpression);
	printf("Infix : %s\nPostfix : %s\n\n", InfixExpression, PostfixExpression);
	
	// 후위 표기식 계산 후 문자열로 저장된 값을 소수로 초기화.
	Result = Calculate(PostfixExpression);
	
	printf("Calculation Result : %f\n", Result);
	
	return 0;
}