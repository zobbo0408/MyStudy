#include "KarpRabin.h"
#include <math.h>

int KarpRabin( char* Text, int TextSize, int Start,
			 char* Pattern, int PatternSize )
{
	int i=0, j=0 ;
	int Coefficient = pow (2, PatternSize-1);
	int HashText 	= Hash (Text, PatternSize);
	int HashPattern = Hash (Pattern, PatternSize);
	
	for (i=Start; i<=TextSize-PatternSize; i++)
	{
		HashText = ReHash (Text, i, PatternSize, HashText, Coefficient);
		
		if(HashPattern == HashText)
		{
			for (j=0; j<PatternSize; j++)
			{
				if(Text[i+j] != Pattern[j])
					break;
			}
			
			if(j >= PatternSize)
				return i;
		}
	}
	
	return -1;
}

int Hash ( char* String, int Size )
{
	int i=0;
	int HashValue = 0;
	
	for (i=0; i<Size; i++)
	{
		// Hi = S[i]*2^(Size-1) + S[i+1]*2^(Size-2) + ... + S[i+Size-1]*2^(0) mod q	(i=0)
		HashValue = String[i] + (HashValue * 2);
	}
	
	return HashValue;
}

int ReHash (char* String, int Start, int Size, int HashPrev, int Coefficient )
{
	if(Start == 0)
		return HashPrev;
	
	// Hi = 2(H(i-1) - S[i-1]*2^(m-1)) + S[i+m-1] mod q  (i>0)
	return String[Start + Size - 1] + ( (HashPrev - String[Start - 1] * Coefficient) * 2 );
}