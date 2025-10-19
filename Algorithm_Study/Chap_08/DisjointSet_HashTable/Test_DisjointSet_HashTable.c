#include "DisjointSet_HashTable.h"

int main()
{
	HashTable* HT = DSHT_CreateHashTable(12289);
	
	HT = DSHT_MakeSet(HT, "apple");
    HT = DSHT_MakeSet(HT, "banana");
    HT = DSHT_MakeSet(HT, "strawberry");
    HT = DSHT_MakeSet(HT, "grape");

	printf("초기 상태: 각 원소는 독립된 집합입니다.\n");
	printf("사과 집합의 대표자: %s\n", DSHT_FindSet(HT, "apple"));
	printf("바나나 집합의 대표자: %s\n", DSHT_FindSet(HT, "banana"));
	printf("포도 집합의 대표자: %s\n", DSHT_FindSet(HT, "grape"));
	
	printf("\n");

	printf("사과와 바나나 집합을 합칩니다.\n");
	DSHT_UnionSet(HT, "apple", "banana");
	
	printf("딸기와 포도 집합을 합칩니다.\n");
	DSHT_UnionSet(HT, "strawberry", "grape");

	// printf("키위와 사과 집합을 합칩니다.\n");
	// DSHT_UnionSet(HT, "키위", "사과");
	
	printf("\n");

	printf("합친 후 상태:\n");
	printf("사과 집합의 대표자: %s\n", DSHT_FindSet(HT, "apple"));
	printf("바나나 집합의 대표자: %s\n", DSHT_FindSet(HT, "banana"));
	printf("딸기 집합의 대표자: %s\n", DSHT_FindSet(HT, "strawberry"));
	printf("포도 집합의 대표자: %s\n", DSHT_FindSet(HT, "grape"));
	// printf("키위 집합의 대표자: %s\n", DSHT_FindSet(HT, "키위"));
	
	printf("\n");

	printf("사과와 바나나는 같은 집합인가요? (0: 아니오, 1: 예): %d\n", 
		(strcmp(DSHT_FindSet(HT, "apple"), DSHT_FindSet(HT, "banana")) == 0));

	// printf("딸기와 키위는 같은 집합인가요? (0: 아니오, 1: 예): %d\n", 
	// 	(strcmp(DSHT_FindSet(HT, "딸기"), DSHT_FindSet(HT, "키위")) == 0));
	
	DSHT_DestroyHashTable(HT);
	
	return 0;
}