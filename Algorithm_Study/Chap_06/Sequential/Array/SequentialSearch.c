#include <stdio.h>

int SequentialSearch(int arr[], int size, int Target)
{
	for(int i=0; i<size; i++)
	{
		if(arr[i] == Target)
		{
			printf("This unit's index is %d\n", i);
			return arr[i];
		}
	}
	return -1;
}

int ARR_MoveToFront(int arr[], int size, int Target)
{
	int Match;
	
	for(int i=0; i<size; i++)
	{
		if(arr[i] == Target)
		{
			printf("This unit's index is %d\n", i);
			Match = arr[i];
			arr[i] = arr[0];
			arr[0] = Match;
			
			return Match;
		}
	}
	
	return -1;
}

int ARR_Transpose(int arr[], int size, int Target)
{
	int Match;
	int Temp;
	
	for(int i=0; i<size; i++)
	{
		if(arr[i] == Target)
		{
			if(i == 0)
			{
				printf("This unit's index is %d\n", i);
				Match = arr[i];
				return Match;
			}
			
			printf("This unit's index is %d\n", i);
			Match = arr[i];
			Temp = arr[i-1];
			arr[i-1] = arr[i];
			arr[i] = Temp;
			
			return Match;
		}
	}
	
	return -1;
}


int main()
{
	int array[] = {5, 3, 1, 4, 2, 8, 6};
	int size = sizeof(array) / sizeof(array[0]);
	
	int a = SequentialSearch(array, size, 4);
	printf("SequentialSearch's Target : %d\n\n", a);
	
	// a = ARR_MoveToFront(array, size, 4);
	// printf("ARR_MoveToFront's Target : %d\n\n", a);
	
	// a = ARR_Transpose(array, size, 6);
	// printf("ARR_MoveToFront's Target : %d\n\n", a);
	
	// a = ARR_Transpose(array, size, 6);
	// printf("ARR_MoveToFront's Target : %d\n\n", a);
	
	printf("array : ");
	for(int i=0; i<7; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	
	return 0;
}