#include "Chaining.h"

HashTable* CHT_CreateHashTable ( int TableSize )
{
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->Table = (List*)malloc(sizeof(Node) * TableSize);
	
	memset(HT->Table, 0, sizeof(List)*TableSize);
	
	HT->TableSize = TableSize;
	
	return HT;
}

Node* CHT_CreateNode ( KeyType Key, ValueType Value )
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode->Key = (char*)malloc(sizeof(char) * (strlen(Key) + 1) );
	NewNode->Value = (char*)malloc(sizeof(char) * (strlen(Value) + 1) );
	
	strcpy(NewNode->Key, Key);
	strcpy(NewNode->Value, Value);
	
	NewNode->NextNode = NULL;
	
	return NewNode;
}

void CHT_DestroyNode ( Node* TheNode )
{
	free (TheNode->Key);
	free (TheNode->Value);
	free (TheNode);
}

void CHT_DestroyList (List L)
{
	if(L==NULL)
		return ;
	
	if(L->NextNode != NULL)
	{
		CHT_DestroyList(L->NextNode);
	}
	
	CHT_DestroyNode(L);
}

void CHT_DestroyHashTable ( HashTable* HT )
{
	int i=0;
	for (i=0; i<HT->TableSize; i++)
	{
		List L = HT->Table[i];
		CHT_DestroyList(L);
	}
	
	free(HT->Table);
	free(HT);
}


void CHT_Set ( HashTable* HT, KeyType Key, ValueType Value )
{
	int Address = CHT_Hash (Key, strlen(Key), HT->TableSize);
	Node* NewNode = CHT_CreateNode(Key, Value);
	
	if(HT->Table[Address] == NULL)
	{
		HT->Table[Address] = NewNode;
	}
	else
	{
		List L = HT->Table[Address];
		NewNode->NextNode = L;
		HT->Table[Address] = NewNode;
		
		printf("Collision Occured : Key(%s), Address(%d)\n", Key, Address);
	}
}

ValueType CHT_Get ( HashTable* HT, KeyType Key )
{
	int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);
	List TheList = HT->Table[Address];
	List Target = NULL;
	
	if(TheList == NULL)
		return NULL;
	
	while(1)
	{
		if(strcmp(TheList->Key, Key) == 0 )		// 참이 0 반환
		{
			Target = TheList;
			break;
		}
		
		if(TheList->NextNode == NULL)
			break;
		else
			TheList = TheList->NextNode;
	}
	
	return Target->Value;
}

int CHT_Hash ( KeyType Key, int KeyLength, int TableSize )
{
	int i=0;
	int HashValue = 0;
	
	for(i=0; i<KeyLength; i++)
		HashValue = (HashValue << 3) + Key[i];
	
	HashValue %= TableSize;
	
	return HashValue;
}