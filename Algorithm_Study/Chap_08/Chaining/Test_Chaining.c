#include "Chaining.h"

int main()
{
	HashTable* HT = CHT_CreateHashTable(12289);
	
	CHT_Set(HT, "MSFT", "Microsoft Corporation");
	// CHT_Set(HT, "APAC", "Apache Org");
	// CHT_Set(HT, "ZYMZZ", "Unisys Ops Check");
	
	// printf("\n");
	
	// printf("Key : %s, Value : %s\n", "MSFT", CHT_Get(HT, "MSFT"));
	// printf("Key : %s, Value : %s\n", "APAC", CHT_Get(HT, "APAC"));
	// printf("Key : %s, Value : %s\n", "ZYMZZ", CHT_Get(HT, "ZYMZZ"));
	
	CHT_DestroyHashTable(HT);
	
	return 0;
}