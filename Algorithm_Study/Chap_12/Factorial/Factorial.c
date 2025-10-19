#include <stdio.h>

typedef unsigned long long ULL;

// 기본적인 팩토리얼 함수, 선형적인 시간복잡도 O(N)을 갖는다.
ULL Common_Factorial (int N)
{
	if (N == 1 || N == 0)
		return 1;
	
	return N * Common_Factorial(N-1);
}

ULL DIV_CON_Calculate ( int Start, int End )
{
	// 1. [Base Case 1]: start가 end보다 크면 (빈 구간), 곱셈의 항등원인 1을 반환
	if (Start > End)
		return 1;
	
	// 2. [Base Case 2]: 구간에 원소가 1개만 남았을 경우, 해당 값을 반환
	if (Start == End)
		return (ULL)Start;
	
	// 3. [Divide]: 구간을 중앙(mid)을 기준으로 두 부분으로 나눔
	int mid = Start + (End - Start) / 2;
	/*
	mid = (Start + End) / 2 로 구하지 않는 이유는
	자료형의 한계값보다 커져 오버플로우가 발생할 우려가 있다.
	소스코드의 코드는 먼저 뺄셈을 수행해 오버플로우를 발생하지 않으며,
	2로 나눈 후 시작점을 더하기에 같은 결과를 나타낸다.
	*/
		
	 // 4. [Conquer]: 두 부분 구간의 곱을 재귀적으로 계산하고, 결과를 합침 (곱셈)
	ULL Left_Cal = DIV_CON_Calculate(Start, mid);
	ULL Right_Cal = DIV_CON_Calculate(mid+1, End);
	/*
	// [문제의 코드] 잘못된 분할
	int mid = start + (end - start) / 2; // mid 계산 (예: 1, 2, 3, 4 -> mid = 2)
	ULL left_product = ProductRange(start, mid-1); // 왼쪽: [start, mid-1]
	ULL right_product = ProductRange(mid, end);    // 오른쪽: [mid, end]
	
	이는 무한 재귀가 발생하여, 스택 오버플로우를 발생시킬 수 있다 -> 코어 덤프 발생
	*/
		
	return Left_Cal * Right_Cal;
}

ULL DIV_CON_Factorial ( int N )
{
	if (N < 0)
		return 0;
	
	if (N == 0)
		return 1;
	
	return DIV_CON_Calculate (1, N);
}

int main()
{
	int N;
	ULL Result;
	N = 10;
	Result = Common_Factorial(N);
	
	printf("%d! = %llu\n", N, Result);
	
	Result = DIV_CON_Factorial(N);
	
	printf("%d! = %llu\n", N, Result);
	
	return 0;
}