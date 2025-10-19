#include <stdio.h>

void BubbleSort(int DataSet[], int Length)
{
	int temp=0;
	
	for(int i=0; i<Length; i++)
	{
		for(int j=0; j<Length-(i+1); j++)
		{
			if(DataSet[j]>DataSet[j+1])
			{
				temp = DataSet[j+1];
				DataSet[j+1] = DataSet[j];
				DataSet[j] = temp;
			}
		}
	}
}

int main() {
	int DataSet[] = {6, 4, 2, 1, 3, 5};
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