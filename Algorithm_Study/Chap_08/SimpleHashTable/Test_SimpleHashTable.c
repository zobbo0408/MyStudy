#include "SimpleHashTable.h"

int main() 
{
	HashTable* HT = SHT_CreateHashTable ( 193 );
	// 나눗셈법으로 구현된 해시 함수가 테이블 내 공간을 효율적으로 사용하기 위해선
	// 2의 제곱수와 거리가 먼 소수를 사용하는 해시 함수가 좋은 성능을 나타냄
	
	// ex. 53(2^5 ~ 2^6), 97(2^6 ~ 2^7), 193(2^7 ~ 2^8), 389(2^8 ~ 2^9) 등
	
	SHT_Set( HT, 418, 32114 );
	SHT_Set( HT, 9, 514 );
	SHT_Set( HT, 27, 8917 );
	SHT_Set( HT, 1031, 286 );
	
	printf("Key : %d, Value : %d\n", 418, SHT_Get(HT, 418));
	printf("Key : %d, Value : %d\n", 9, SHT_Get(HT, 9));
	printf("Key : %d, Value : %d\n", 27, SHT_Get(HT, 27));
	printf("Key : %d, Value : %d\n", 1031, SHT_Get(HT, 1031));
	
	SHT_DestroyHashTable( HT );
	
	return 0;
}