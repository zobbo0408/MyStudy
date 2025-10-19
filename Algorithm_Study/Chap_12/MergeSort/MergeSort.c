#include <stdio.h>
#include <stdlib.h>

void MergeSort ( int DataSet[], int StartIndex, int EndIndex );
void Merge ( int DataSet[], int StartIndex, int MiddleIndex, int EndIndex );

void MergeSort ( int DataSet[], int StartIndex, int EndIndex )
{
	int MiddleIndex;
	
	if( EndIndex - StartIndex < 1)
		return ;
	
	MiddleIndex = (StartIndex + EndIndex) / 2;
	
	MergeSort( DataSet, StartIndex, MiddleIndex );
	MergeSort( DataSet, MiddleIndex+1, EndIndex );
	
	Merge( DataSet, StartIndex, MiddleIndex, EndIndex );
}

void Merge ( int DataSet[], int StartIndex, int MiddleIndex, int EndIndex )
{
	int i;
	int LeftIndex = StartIndex;
	int RightIndex = MiddleIndex+1;
	int DestIndex = 0;
	
	int* Destination = (int*) malloc ( sizeof(int) * (EndIndex-StartIndex+1) );
	
	// 나뉘어진 값들에서 각각의 앞의 수를 비교 후 보조 배열에 초기화.
	while (LeftIndex <= MiddleIndex && RightIndex <= EndIndex)
	{
		if(DataSet[LeftIndex] < DataSet[RightIndex])
		{
			Destination[DestIndex] = DataSet[LeftIndex];
			LeftIndex++;
		}
		
		else
		{
			Destination[DestIndex] = DataSet[RightIndex];
			RightIndex++;
		}
		
		DestIndex ++;
	}
	
	// 위 while문에서 정렬 후 남은 수를 LeftIndex부터 초기화. (남은 수 중 LeftIndex의 값이 RightIndex의 값보다 클 순 없음)
	while(LeftIndex <= MiddleIndex)
		Destination[DestIndex++] = DataSet[LeftIndex++];
	
	while(RightIndex <= EndIndex)
		Destination[DestIndex++] = DataSet[RightIndex++];
	
	DestIndex = 0;
	
	// 원본 배열에 정렬된 보조배열을 재 초기화.
	for(i=StartIndex; i<=EndIndex; i++)
		DataSet[i] = Destination[DestIndex++];
	
	free(Destination);
}

int main() {
	int DataSet[] = {334, 6, 4, 2, 3, 1, 5, 117, 12, 34};
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;
	
	MergeSort(DataSet, i, Length-1);
	
	for(i=0; i<Length; i++)
		printf("%d ", DataSet[i]);
	
	printf("\n");
	
	return 0;
}