#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include "LinkedListStack.h"

typedef enum {
	LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
	PLUS = '+', MINUS = '-',
	MULTIPLY = '*', DIVIDE = '/',
	SPACE = ' ', OPERAND
} SYMBOL;

int IsNumber (char Cipher); // 해당 문자가 숫자 또는 .인지 확인
unsigned int GetNextToken (char* Expression, char* Token, int* Type);
int GetPriority (char Operator, int InStack);
int IsPrior (char Operator1, char Operator2);
void GetPostfix (char* InfixExpression, char* PostfixExpression);
double Calculate (char* PostfixExpression);

#endif