#ifndef BOYERMOORE_H
#define BOYERMOORE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int BoyreMoore ( char* Text, int TextSize, int Start,
			   	char* Pattern, int PatternSize );
void BuildGST ( char* Pattern, int PatternSize, int* PosOfBorder, int* GoodSuffTable );
void BuildBST ( char* Pattern, int PatternSize, int* BadCharTable );

int Max ( int A, int B );

#endif