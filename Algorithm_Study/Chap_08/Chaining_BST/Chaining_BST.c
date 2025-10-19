#include "Chaining_BST.h"

HashTable* BHT_CreateHashTable ( int TableSize )
{
	HashTable* HT = (HashTable*) malloc (sizeof (HashTable) );
	HT->Table = (List*) malloc (sizeof(Node) * TableSize);
	
	memset(HT->Table, 0, sizeof(List) * TableSize);
	
	HT->TableSize = TableSize;
	
	return HT;
}

Node* BHT_CreateNode ( KeyType Key, ValueType Value )
{
	Node* TheNode = (Node*) malloc (sizeof(Node));
	TheNode->Key = (char*) malloc ( sizeof(char) * (strlen(Key) + 1) );
	TheNode->Value = (char*) malloc ( sizeof(char) * (strlen(Value) + 1) );
	
	strcpy(TheNode->Key, Key);
	strcpy(TheNode->Value, Value);
	
	TheNode->Left = NULL;
	TheNode->Right = NULL;
	
	return TheNode;
}

void BHT_DestroyNode ( Node* TheNode )
{
	free (TheNode->Key);
	free (TheNode->Value);
	free (TheNode);
}

void BHT_DestroyList ( List L )
{
	if ( L == NULL )
		return ;
	
	if (L->Left != NULL)
		BHT_DestroyNode (L->Left);
	else if (L->Right != NULL)
		BHT_DestroyNode (L->Right);
	
	L->Left = NULL;
	L->Right = NULL;
	
	BHT_DestroyNode(L);
}

void BHT_DestroyHashTable ( HashTable* HT )
{
	int i=0;
	for(i=0; i < HT->TableSize; i++)
	{
		List L = HT->Table[i];
		BHT_DestroyList (L);
	}
	
	free ( HT->Table );
	free ( HT );
}

void BHT_Insert(Node* Tree, Node* Child)
{
    // strcmp 결과를 변수에 저장하여 여러 번 호출하지 않도록 최적화
	// 문자열을 비교할 땐 Tree->Key < Child->Key와 같이 단순 비교는 안됨.
	// 코어 덤프 원인
    int cmp = strcmp(Tree->Key, Child->Key);

    if (cmp < 0) { // Tree->Key < Child->Key
        if (Tree->Right == NULL)
            Tree->Right = Child;
        else
            BHT_Insert(Tree->Right, Child);
    } 
	
	else if (cmp > 0) { // Tree->Key > Child->Key
        if (Tree->Left == NULL)
            Tree->Left = Child;
        else
            BHT_Insert(Tree->Left, Child);
    } 
	
	else {
        // 키가 이미 존재하는 경우: 값 업데이트 또는 무시
        // 여기서는 값을 업데이트하는 것으로 가정합니다.
        // free(Tree->Value);
        // Tree->Value = Child->Value;
        // BHT_DestroyNode(Child); // 메모리 누수 방지를 위해 Child 노드 해제
    }
}

void BHT_Set(HashTable* HT, KeyType Key, ValueType Value)
{
    int Address = BHT_Hash(Key, strlen(Key), HT->TableSize);
    Node* NewNode = BHT_CreateNode(Key, Value);

    if (HT->Table[Address] == NULL) {
        HT->Table[Address] = NewNode;
    } 
	
	else {
        Node* Tree = HT->Table[Address];
        printf("Collision Occured : Key(%s), Address(%d)\n", Key, Address);

        // BHT_Insert 함수로 새 노드를 삽입
        BHT_Insert(Tree, NewNode);
    }
}

ValueType BHT_Get ( HashTable* HT, KeyType Key )
{
	int Address = BHT_Hash(Key, strlen(Key), HT->TableSize);
	List TheList = HT->Table[Address];
	List Target = NULL;
	
	if(TheList == NULL)
		return NULL;
	
	while (1)
	{
		int cmp = strcmp(TheList->Key, Key);
		
		if( cmp == 0 )		// 참이 0 반환
		{
			Target = TheList;
			break;
		}
		
		else if ( cmp < 0 )
		{
			TheList = TheList->Right;
		}
		else
			TheList = TheList->Left;
	}
	
	return Target->Value;
}

int BHT_Hash ( KeyType Key, int KeyLength, int TableSize )
{
	int i=0;
	int HashValue = 0;
	
	for(i=0; i<KeyLength; i++)
		HashValue = (HashValue << 3) + Key[i];
	
	HashValue %= TableSize;
	
	return HashValue;
}