#include "BoyreMoore.h"

int BoyreMoore ( char* Text, int TextSize, int Start,
			   	char* Pattern, int PatternSize )
{
	int BadCharTable[128];		// 나쁜 문자열 테이블, 모든 문자를 입력할 수 있는 테이블
	int* GoodSuffTable = (int*)calloc ( PatternSize+1, sizeof(int) );		// 착한 접미부 테이블
	int* PosOfBorder = (int*)calloc ( PatternSize+1, sizeof(int) );			// 접미부의 가장 넓은 경계의 시작 위치
	int i = Start;
	int j = 0;
	
	int Position = -1;
	
	BuildBST(Pattern, PatternSize, BadCharTable);
	BuildGST(Pattern, PatternSize, PosOfBorder, GoodSuffTable);
	
	while (i <= TextSize - PatternSize)
	{
		j = PatternSize - 1;
		
		while (j >= 0 && Pattern[j] == Text[i+j])
		{
			j--;
		}
		
		if(j < 0)
		{
			Position = i;
			break;
		}
		else
			i += Max( GoodSuffTable[j+1], j - BadCharTable[ Text[i+j] ] );
	}
	
	free(PosOfBorder);
	free(GoodSuffTable);
	
	return Position;
}

void BuildGST ( char* Pattern, int PatternSize, int* PosOfBorder, int* GoodSuffTable )
{
	// Case 1, 불일치 발생 시 착한 접미부가 패턴의 불일치 지점 이전에 존재하는 경우
	int i = PatternSize;
	int j = PatternSize + 1;
	
	PosOfBorder[i] = j;		// 빈 접미부 ''는 경계를 가질 수 없으므로 PatternSize + 1 (7)이 된다.
	
	// 패턴의 길이만큼 반복
	while (i>0)
	{
		// 패턴에서 경계 찾기
		while (j <= PatternSize && Pattern[i-1] != Pattern[j-1] )
		{
			if (GoodSuffTable[j] == 0)
				GoodSuffTable[j] = j - i;
			
			j = PosOfBorder[j];		// 경계를 이용해서 while문 탈출로 사용
		}
		
		i--;
		j--;
		
		PosOfBorder[i] = j; // 찾아낸 경계의 시작점 저장
	}
	
	// Case 2
	j = PosOfBorder[0];
	
	for (i=0; i<=PatternSize; i++)
	{
		if (GoodSuffTable[i] == 0)
			GoodSuffTable[i] = j; // 이동거리가 0인 항목에 대해서만 첫 '접미부의 가장 넓은 경계의 시작위치 입력'
			
		if ( i == j )
			j = PosOfBorder[j];
	}
}

void BuildBST ( char* Pattern, int PatternSize, int* BadCharTable )
{
	int i, j;
	
	// 모든 문자를 입력할 수 있는 테이블에 -1로 초기화
	for (i=0; i<128; i++)
		BadCharTable[i] == -1;
	
	// 패턴의 문자 위치를 테이블에 기록하며, 중복되는 문자는 가장 마지막 문자가 적용
	for (j=0; j<PatternSize; j++)
		BadCharTable[ Pattern[j] ] = j;
}

int Max ( int A, int B )
{
	if ( A > B )
		return A;
	else
		return B;
}