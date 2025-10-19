#include <stdio.h>
#include <stdlib.h>

// 기존 Merge 함수는 그대로 사용, 바텀 업 알고리즘
void Merge ( int DataSet[], int StartIndex, int MiddleIndex, int EndIndex ); 

void MergeSort_Iterative ( int DataSet[], int Length )
{
    // SubGroupSize: 현재 병합할 부분 배열의 크기 (1, 2, 4, 8, ...)
    int SubGroupSize = 1;
    
    // SubGroupSize가 배열 길이보다 작을 때까지 반복
    while (SubGroupSize < Length)
    {
        int StartIndex = 0;
        
        // StartIndex: 현재 단계에서 병합을 시작할 위치
        while (StartIndex < Length - SubGroupSize)
        {
            // 1. 왼쪽 그룹의 끝: StartIndex + SubGroupSize - 1
            int MiddleIndex = StartIndex + SubGroupSize - 1;
            
            // 2. 오른쪽 그룹의 끝: MiddleIndex + SubGroupSize (배열 범위를 넘지 않도록 제한)
            int EndIndex = StartIndex + (2 * SubGroupSize) - 1;
            
            if (EndIndex >= Length)
                EndIndex = Length - 1;

            // 3. 두 개의 정렬된 부분 배열을 병합
            Merge(DataSet, StartIndex, MiddleIndex, EndIndex);
            
            // 다음 그룹의 시작 위치로 이동
            StartIndex = EndIndex + 1;
        }
        
        // 부분 배열 크기를 두 배로 증가 (1 -> 2 -> 4 -> 8 ...)
        SubGroupSize *= 2;
    }
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
	
	// 재귀 대신 반복문 기반 함수 호출
	MergeSort_Iterative(DataSet, Length); 
	
	for(i=0; i<Length; i++)
		printf("%d ", DataSet[i]);
	
	printf("\n");
	
	return 0;
}