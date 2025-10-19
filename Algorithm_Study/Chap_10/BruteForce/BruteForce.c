#include "BruteForce.h"

int BruteForce (char* Text, int TextSize, int Start, char* Pattern, int PatternSize)
{
	int i = 0;
	int j = 0;
	
	for (i=Start; i<TextSize - PatternSize; i++)
	{
		for (j=0; j<PatternSize; j++)
		{
			if(Text[i+j] != Pattern[j])
				break;
		}
		
		// 안쪽 for 루프가 break 없이 끝까지 실행되었다는 것은, j가 PatternSize와 같거나 커졌다는 것을 의미한다.
		if(j >= PatternSize)
			return i;
	}
	
	return -1;
}