#include <stdio.h>
#include <string.h>

void InsertionSort(int Dataset[], int Length) 
{
	int value = 0;
	
	for(int i=1; i<Length; i++)
	{
		if(Dataset[i-1] <= Dataset[i])
			continue;
		
		value = Dataset[i];
		
		for(int j=0; j<i; j++)
		{
			if(Dataset[j] > value)
			{
				memmove(&Dataset[j+1], &Dataset[j], sizeof(Dataset[0]) * (i-j));
				Dataset[j] = value;
				break;
			}
		}
	}
}

int main() {
	int DataSet[] = {6, 4, 2, 1, 3, 5}; // 462135 -> 246135 -> 124635 -> 123465 -> 123456
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	
	printf("Before InsertionSorting ... ");
	for(int i=0; i<Length; i++)
	{
		printf("%d ", DataSet[i]);
	}
	printf("\n\n");
	
	InsertionSort(DataSet, Length);
	
	printf("After InsertionSorting ... ");
	for(int i=0; i<Length; i++)
	{
		printf("%d ", DataSet[i]);
	}
	printf("\n");
	
	return 0;
}