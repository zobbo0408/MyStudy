/*
배열이 이미 정렬되어 있는 경우, 필요없는 비교를 수행하지 않고,
함수를 종료할 수 있게 버블정렬 개선. 
	=> 내부의 for 문이 수행되면 안된다.
	=> 외부 for 문에서 정렬이 되었는지 확인해야 함.
*/

#include <stdio.h>



void BubbleSort(int DataSet[], int Length)
{
	int temp=0;
	int count = 0;
	
	for(int i=0; i<Length; i++)
	{
		count = 0;
		
		for(int j=0; j<Length-(i+1); j++)
		{
			if(DataSet[j]>DataSet[j+1])
			{
				temp = DataSet[j+1];
				DataSet[j+1] = DataSet[j];
				DataSet[j] = temp;
				count ++;
			}
		}
		if ( count == 0 )
		{
			printf("i는 %d에서 break.\n", i);
			break;
		}
	}
}

int main() {
	// int DataSet[] = {6, 4, 2, 1, 3, 5};
	// int DataSet[] = {3, 1, 4, 2, 5, 6};
	int DataSet[] = {1, 2, 3, 4, 5, 6};
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	
	printf("Before BubbleSorting ... ");
	for(int i=0; i<Length; i++)
	{
		printf("%d ", DataSet[i]);
	}
	printf("\n\n");
	
	BubbleSort(DataSet, Length);
	
	printf("After BubbleSorting ... ");
	for(int i=0; i<Length; i++)
	{
		printf("%d ", DataSet[i]);
	}
	printf("\n");
	
	return 0;
}