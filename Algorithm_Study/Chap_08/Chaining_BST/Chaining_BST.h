#ifndef CHAINING_BST_H
#define CHAINING_BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* KeyType;
typedef char* ValueType;

typedef struct tagNode
{
	KeyType Key;
	ValueType Value;
	
	struct tagNode* Left;
	struct tagNode* Right;
} Node;

typedef Node* List;

typedef struct tagHashTable
{
	int TableSize;
	List* Table;
} HashTable;

HashTable* BHT_CreateHashTable ( int TableSize );
void BHT_DestroyHashTable ( HashTable* HT );

Node* BHT_CreateNode ( KeyType Key, ValueType Value );
void BHT_DestroyNode ( Node* TheNode );

void BHT_Set ( HashTable* HT, KeyType Key, ValueType Value );
ValueType BHT_Get ( HashTable* HT, KeyType Key );
int BHT_Hash ( KeyType Key, int KeyLength, int TableSize );

#endif