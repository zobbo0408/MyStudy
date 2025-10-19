#include "SimpleHashTable.h"

HashTable* SHT_CreateHashTable ( int TableSize )
{
	HashTable* HT = (HashTable*)malloc(sizeof( HashTable ));
	HT->TableSize = TableSize;
	HT->Table = (Node*)malloc( sizeof( Node ) * HT->TableSize );
	
	return HT;
}

void SHT_Set ( HashTable* HT, KeyType Key, ValueType Value )
{
	int Address = SHT_Hash( Key, HT->TableSize ); // 주소 계산
	
	HT->Table[Address].Key = Key;
	HT->Table[Address].Value = Value;
}

ValueType SHT_Get ( HashTable* HT, KeyType Key )
{
	int Address = SHT_Hash( Key, HT->TableSize );
	
	return HT->Table[Address].Value;
}

void SHT_DestroyHashTable ( HashTable* HT )
{
	free ( HT->Table );
	free ( HT );
}

int SHT_Hash ( KeyType Key, int TableSize )
{
		// 일반적인 나눗셈법 적용한 해시 함수
	return Key % TableSize;
}

// int SHT_Hash( char* Key, int KeyLength, int TableSize )
// {
// 	// 자릿수 접기를 적용한 나눗셈법 해시 함수로
// 	// 문자열의 각 요소를 ASKII 코드 번호로 변환하여 더한다. (아스키는 0~127까지)
// 	// 이때 일반적인 자릿수 접기는 한 자리에 127자, 10자리면 최대 1270자밖에 가용을 못하고,
// 	// 이는 1271~12288만큼의 주소를 활용을 못함.
// 	// 따라서 사용못하는 세개의 비트를 사용하기 위해 쉬프트연산을 사용하여
// 	// 루프가 반복될 때마다 HashValue를 왼쪽으로 3비트씩 밀어올려 코드를 더한다.
// 	int i = 0;
// 	int HashValue = 0;
	
// 	for( i=0; i<KeyLength; i++ )
// 	{
// 		HashValue = (HashValue << 3) + Key[i];
// 	}
	
// 	return HashValue % TableSize;
// }