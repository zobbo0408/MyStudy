// 최소한의 지폐와 동전으로 거슬러주는 탐욕알고리즘
// DP보다 빠르지만, 항상 최적의 값을 주는 것은 아니다.
// 동전이 400원짜리가 있고 거스를 돈이 800이라면
// 400 * 2가 이상적이지만, 여기선 500*1, 100*3 총 4개로 나옴.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MakingChange.h"

int Compare ( const void* a, const void* b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;

    if(_a < _b)
        return 1;
    else
        return -1;
}

int main() 
{
    int i=0;
    int Pay = 0;            // 손님이 지불하는 돈
    int Price = 0;          // 가격
    int ChangeAmount = 0;   // 거슬러줄 돈의 총 금액
    int UnitCount = 0;      // 동전의 가짓수
    int* CoinUnits = NULL;  // 동전의 단위
    int* Change = NULL;     // 거슬러주는 동전의 갯수
    bool Divise = false;   // 인수 존재 유무
    int Divisor = 0;

    printf("동전의 가짓수를 입력하세요 : ");
    scanf("%d", &UnitCount);

    CoinUnits = (int*)malloc(sizeof(int) * UnitCount);
    Change = (int*)malloc(sizeof(int) * UnitCount);

    for(i=0; i<UnitCount; i++)
    {
        printf("[%d] 번째 동전의 단위를 입력하세요 : ", i);
        scanf("%d", &CoinUnits[i]);
    }

    qsort(CoinUnits, UnitCount, sizeof(int), Compare); // 입력받은 동전들을 내림차순으로 정렬

    printf("물건 가격을 입력하세요 : ");
    scanf("%d", &Price);

    printf("손님이 지불한 돈을 입력하세요 : ");
    scanf("%d", &Pay);

    ChangeAmount = Pay-Price;       

    for ( i=0; i<UnitCount; i++)
    {
        if( ChangeAmount % CoinUnits[i] == 0 )
            {
                Divise = true;
                Divisor = CoinUnits[i];
                break;
            }
    }
    if(Divise == true)
        GetChangeFromDivisor(ChangeAmount, Divisor, CoinUnits, Change, UnitCount );
    else
        GetChange(ChangeAmount, CoinUnits, Change, UnitCount);

    PrintChange(CoinUnits, Change, UnitCount);

    return 0;
}