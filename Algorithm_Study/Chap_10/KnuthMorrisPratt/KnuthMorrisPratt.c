#include "KnuthMorrisPratt.h"

void Preprocess ( char* Pattern, int PatternSize, int* Border )
{
	int i=0;
	int j=-1;
	
	Border[0] = -1;
	
	while ( i < PatternSize )
	{
		while ( j > -1 && Pattern[i] != Pattern[j] )
			j = Border[j];
		
		i++;
		j++;
		
		Border[i] = j;
	}
}

int KnuthMorrisPratt ( char* Text, int TextSize, int Start,
					 	char* Pattern, int PatternSize )
{
	int i = Start;
	int j = 0;
	int Position = -1;
	
	int* Border = (int*)calloc(PatternSize + 1, sizeof(int));
	
	Preprocess( Pattern, PatternSize, Border );
	
	while ( i < TextSize ) // 텍스트를 순회하는 바깥 루프
	{
    	while (j >= 0 && Text[i] != Pattern[j] ) // 불일치 발생 시
        	j = Border[j]; // 패턴을 j만큼 이동 (불필요한 비교 생략)
    
    	i++;
    	j++;
    
    	if( j == PatternSize ) // 패턴 전체가 일치하는 경우
    	{
        	Position = i - j;
        	break; // 탐색 종료
    	}
	}
	
	free( Border );
	return Position;
}

