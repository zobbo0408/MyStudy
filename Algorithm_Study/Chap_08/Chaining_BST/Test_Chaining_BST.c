#include "Chaining_BST.h"

int main()
{
	HashTable* HT = BHT_CreateHashTable(12289);
	
	BHT_Set(HT, "MSFT", "Microsoft Corporation");
	BHT_Set(HT, "APAC", "Apache Org");
	BHT_Set(HT, "ZYMZZ", "Unisys Ops Check");
	
	printf("\n");
	
	printf("Key : %s, Value : %s\n", "MSFT", BHT_Get(HT, "MSFT"));
	printf("Key : %s, Value : %s\n", "APAC", BHT_Get(HT, "APAC"));
	printf("Key : %s, Value : %s\n", "ZYMZZ", BHT_Get(HT, "ZYMZZ"));
	
	BHT_DestroyHashTable(HT);
	
	return 0;
}