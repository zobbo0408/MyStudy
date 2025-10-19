#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* ElementType;

typedef struct tagNode
{
	ElementType Key;
	ElementType Value;
	
	struct tagNode* NextNode;
} Node;

typedef Node* List;

typedef struct tagHashTable
{
	int TableSize;
	List* Table;
} HashTable;

HashTable* DSHT_CreateHashTable(int TableSize);
void DSHT_DestroyHashTable(HashTable* HT);
Node* DSHT_CreateNode(ElementType Key, ElementType Value);
void DSHT_DestroyList(List L);
void DSHT_DestroyNode(Node* TheNode);

void DSHT_Set(HashTable* HT, ElementType Key, ElementType Value);
ElementType DSHT_Get(HashTable* HT, ElementType Key);
int DSHT_Hash(ElementType Key, int KeyLength, int TableSize);

void DSHT_UnionSet(HashTable* HT, ElementType Key1, ElementType Key2);
HashTable* DSHT_MakeSet(HashTable* HT, ElementType Key);
ElementType DSHT_FindSet(HashTable* HT, ElementType Key);