#include "DisjointSet_HashTable.h"

HashTable* DSHT_CreateHashTable(int TableSize)
{
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->Table = (List*)malloc(sizeof(Node*) * TableSize); // 수정된 부분: Node*의 크기만큼 할당
	
	memset(HT->Table, 0, sizeof(List) * TableSize);
	
	HT->TableSize = TableSize;
	
	return HT;
}

Node* DSHT_CreateNode(ElementType Key, ElementType Value) // 매개변수 추가
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode->Key = (char*)malloc(sizeof(char) * (strlen(Key) + 1));
	NewNode->Value = (char*)malloc(sizeof(char) * (strlen(Value) + 1)); // Value 길이로 할당
	
	strcpy(NewNode->Key, Key);
	strcpy(NewNode->Value, Value);
	
	NewNode->NextNode = NULL;
	
	return NewNode;
}

void DSHT_DestroyHashTable(HashTable* HT)
{
	int i = 0;
	for (i = 0; i < HT->TableSize; i++)
	{
		List L = HT->Table[i];
		DSHT_DestroyList(L);
	}
	
	free(HT->Table);
	free(HT);
}

void DSHT_DestroyList(List L)
{
	if(L == NULL)
		return;
	
	DSHT_DestroyList(L->NextNode);
	DSHT_DestroyNode(L);
}

void DSHT_DestroyNode(Node* TheNode)
{
	if (TheNode) {
        free(TheNode->Key);
        free(TheNode->Value);
        free(TheNode);
    }
}

void DSHT_Set(HashTable* HT, ElementType Key, ElementType Value)
{
    int Address = DSHT_Hash(Key, strlen(Key), HT->TableSize);
    List currentNode = HT->Table[Address];

    // Check if the key already exists
    while (currentNode != NULL) {
        if (strcmp(currentNode->Key, Key) == 0) {
            // Update the existing node's value
            free(currentNode->Value);
            currentNode->Value = (char*)malloc(sizeof(char) * (strlen(Value) + 1));
            strcpy(currentNode->Value, Value);
			
			printf("Change the Represent : Key(%s), Address(%d)\n", Key, Address);
            return;
        }
        currentNode = currentNode->NextNode;
    }
    
    // Create a new node and append it to the end of the list
    Node* NewNode = DSHT_CreateNode(Key, Value);

    if (HT->Table[Address] == NULL) 
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

ElementType DSHT_Get(HashTable* HT, ElementType Key)
{
	int Address = DSHT_Hash(Key, strlen(Key), HT->TableSize);
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

int DSHT_Hash(ElementType Key, int KeyLength, int TableSize)
{
	int i = 0;
	int HashValue = 0;
	
	for (i = 0; i < KeyLength; i++)
		HashValue = (HashValue << 3) + Key[i];
	
	HashValue %= TableSize;
	
	return HashValue;
}

HashTable* DSHT_MakeSet(HashTable* HT, ElementType Key)
{
    if (HT == NULL) {
        HT = DSHT_CreateHashTable(12289);
    }
    DSHT_Set(HT, Key, Key);
    return HT;
}

ElementType DSHT_FindSet(HashTable* HT, ElementType Key)
{
    ElementType Parent = DSHT_Get(HT, Key); // value 값
    if (Parent == NULL || strcmp(Parent, Key) == 0) {
        return Key;
    }
    return DSHT_FindSet(HT, Parent);
}

void DSHT_UnionSet(HashTable* HT, ElementType Key1, ElementType Key2)
{
    ElementType Root1 = DSHT_FindSet(HT, Key1);
    ElementType Root2 = DSHT_FindSet(HT, Key2);

    if (Root1 == NULL || Root2 == NULL) {
        return;
    }

    if (strcmp(Root1, Root2) != 0) {
        DSHT_Set(HT, Root2, Root1);
    }
}