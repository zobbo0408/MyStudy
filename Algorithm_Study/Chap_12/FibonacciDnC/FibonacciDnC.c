#include <stdio.h>
#include <string.h>

typedef unsigned long ULONG;

// 2X2 행렬 정의
typedef struct tagMatrix2X2
{
	ULONG Data[2][2];
} Matrix2X2;

Matrix2X2 Matrix2X2_Multiply ( Matrix2X2 A, Matrix2X2 B )
{
	Matrix2X2 C;
	
	C.Data[0][0] = A.Data[0][0] * B.Data[0][0] + A.Data[0][1] * B.Data[1][0];
	C.Data[0][1] = A.Data[0][0] * B.Data[0][1] + A.Data[0][1] * B.Data[1][1];
	
	C.Data[1][0] = A.Data[1][0] * B.Data[0][0] + A.Data[1][1] * B.Data[1][0];
	C.Data[1][1] = A.Data[1][0] * B.Data[0][1] + A.Data[1][1] * B.Data[1][1];
	
	return C;
}

Matrix2X2 Matrix2X2_Power ( Matrix2X2 A, int n )
{
	if(n>1)
	{
		// 제곱수를 반으로 나눠 다시 Matrix2X2_Power() 함수를 재귀 호출
		// 재귀를 사용하지 않고 log2(N)을 이용해서 for문을 반복한다면,
		// 재귀를 통한 비용을 지출하지 않아도 됨.
		A = Matrix2X2_Power(A, n/2);
		
		// 그 값을 제곱 함으로써 다음 수열을 구함. (ex. F1 -> F2, 이때 N은 반절 삭감.)
		A = Matrix2X2_Multiply(A, A);
		
		// N이 홀수인 경우, n/2를 수행할 때 연산자 /에 의해 나머지 1은 버려짐.
		// 따라서 A에 행렬을 곱하여 버려진 나머지 보완
		if(n & 1)
		{
			Matrix2X2 B;
			B.Data[0][0] = 1; B.Data[0][1] = 1;
			B.Data[1][0] = 1; B.Data[1][1] = 0;
			
			A = Matrix2X2_Multiply(A, B);
		}
	}
	
	return A;
}

// 연습문제 _ 재귀를 사용하지 않아 비용을 줄이기 : 반복문 사용
Matrix2X2 Matrix2X2_Power_NotRecursion ( Matrix2X2 A, int n )
{
    // n=1 이하의 예외 처리
    if (n <= 0) {
        Matrix2X2 Identity;
        memset(&Identity, 0, sizeof(Matrix2X2));
        Identity.Data[0][0] = 1;
        Identity.Data[1][1] = 1;
        return Identity; // 항등 행렬 반환
    }
    if (n == 1) {
        return A; // A 자체 반환
    }

    // 결과 행렬 (Result)을 항등 행렬로 초기화: Result = I
    Matrix2X2 Result;
    memset(&Result, 0, sizeof(Matrix2X2));
    Result.Data[0][0] = 1;
    Result.Data[1][1] = 1;

    // A^1 행렬 (Base)을 A로 초기화: Base = A
    Matrix2X2 Base = A;

    // n의 2진수 비트를 검사하며 반복
    while (n > 0)
    {
        // 1. n의 현재 최하위 비트가 1이면 (n이 홀수이면)
        // Base 행렬을 Result에 곱함 (Result = Result * Base^(2^k))
        if (n & 1)
        {
            Result = Matrix2X2_Multiply(Result, Base);
        }

        // 2. Base 행렬을 제곱함 (Base = Base * Base)
        // 다음 루프를 위해 Base = A^(2 * (2^k))로 만듦
        Base = Matrix2X2_Multiply(Base, Base);

        // 3. n을 오른쪽으로 1비트 이동 (n = n / 2)
        n >>= 1;
    }

    return Result;
}

// 행렬과 분할&정복 알고리즘을 이용한 피보나치
ULONG Fibonacci ( int N )
{
	Matrix2X2 A;
	
	// 행렬 초기화
	A.Data[0][0] = 1; A.Data[0][1] = 1;
	A.Data[1][0] = 1; A.Data[1][1] = 0;
	
	// 행렬 제곱 계산
	// A = Matrix2X2_Power (A, N);
	A = Matrix2X2_Power_NotRecursion (A, N);
	
	// 구하고자 하는 피보나치 수인 Fn 반환
	return A.Data[0][1];
}

int main(){
	int N = 46;
	ULONG Result = Fibonacci(N);
	
	printf("Fibonacci(%d) = %lu\n", N, Result);
	
	return 0;
}