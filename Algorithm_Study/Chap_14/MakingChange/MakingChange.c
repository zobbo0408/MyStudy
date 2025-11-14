// 최소한의 지폐와 동전으로 거슬러주는 탐욕알고리즘
#include <stdio.h>
#include "MakingChange.h"

void GetChange ( int ChangeAmount, int CoinUnits[], int Change[], int Size )
{
    int i=0;

    for (i=0; i<Size; i++)
    {
        Change[i] = CountCoins( ChangeAmount, CoinUnits[i] );
        ChangeAmount = ChangeAmount - ( CoinUnits[i] *  Change[i] );        // 위에서 구한 코인의 갯수와 그 금액을 곱한 값을 거스를 돈에서 제외
    }
}

// 탐욕 알고리즘에선 CoinUnits를 내림차순으로 정렬해서 첫번째 것 부터 거슬러 줄 돈의 최대한 만큼
// 구함.
int CountCoins ( int Amounts, int CoinUnit )
{
    int CoinCount = 0;      // 해당 코인의 갯수
    int CurrentAmount = Amounts;    // 당장 거슬러 줄 돈

    while( CurrentAmount >= CoinUnit )
    {
        CoinCount++;
        CurrentAmount = CurrentAmount - CoinUnit;   // 큰 동전부터 최대한의 갯수 뽑기
    }

    return CoinCount;
}

// 가지고 있는 돈에서 가장 합리적인 방법으로 거슬러주기.
void GetChangeFromDivisor ( int ChangeAmount, int Divisor, int CoinUnits[], int Change[], int Size )
{
    for (int i=0; i<Size; i++)
    {
        if( CoinUnits[i] == Divisor )
        {
            Change[i] = CountCoins( ChangeAmount, CoinUnits[i] );
        }
    }
}

void PrintChange ( int CoinUnits[], int Change[], int Size )
{
    int i=0;

    for(i=0; i<Size; i++)
        printf("%8d원 : %d개\n", CoinUnits[i], Change[i]);
}