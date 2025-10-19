#ifndef KARPRABIN_H
#define KARPRABIN_H

#include <stdio.h>
#include <string.h>

int KarpRabin( char* Text, int TextSize, int Start,
			 char* Pattern, int PatternSize );

// 본문[0...Size-1]과 패턴의 해시값을 구하는 함수, Size = PatternSize
int Hash ( char* String, int Size );

// 본문[i...i+Size-1]의 해시값을 구하는 함수 (롤링 해시 함수), Size = PatternSize
int ReHash (char* String, int Start, int Size, int HashPrev, int Coefficient );

#endif