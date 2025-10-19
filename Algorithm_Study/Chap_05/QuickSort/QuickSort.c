#include <stdio.h>

void Swap (int* A, int* B)
{
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

int Partition (int DataSet[], int Left, int Right)
{
	int First = Left; // 처음은 0 또는 시작 인덱스
	int Pivot = DataSet[First]; // 배열의 시작 값이 기준 == 6
	
	++Left; // First에 할당 후 증가
	
	// Left와 Right는 양 끝에서부터 기준 대상(Pivot)보다 크거나 작은 요소를 탐색하는 정찰병
	// 이 두 변수가 만나면 while문은 종료.
	while (Left <= Right)
	{
		while (DataSet[Left] <= Pivot && Left < Right)
			++Left;
		
		while (DataSet[Right] >= Pivot && Left <= Right)
			--Right;
		
		if(Left < Right)
			Swap(&DataSet[Left], &DataSet[Right]);
		else
			break;
	}
	
	Swap(&DataSet[First], &DataSet[Right]);
	
	return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
	if(Left < Right)
	{
		int Index = Partition(DataSet, Left, Right);
		
		QuickSort(DataSet, Left, Index-1);
		QuickSort(DataSet, Index+1, Right);
	}
}

int main() {
	int DataSet[] = {6, 4, 2, 1, 3, 5};
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	
	printf("Before QuickSorting ... ");
	for(int i=0; i<Length; i++)
	{
		printf("%d ", DataSet[i]);
	}
	printf("\n\n");
	
	QuickSort(DataSet, 0, Length-1);
	
	printf("After QuickSorting ... ");
	for(int i=0; i<Length; i++)
	{
		printf("%d ", DataSet[i]);
	}
	printf("\n");
	
	return 0;
}