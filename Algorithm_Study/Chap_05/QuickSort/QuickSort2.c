// qsort() 사용 예제
/*
void qsort(
		void *base, 	// 정렬 대상 배열의 주소
		size_t num, 	// 데이터 요소의 개수
		size_t width, 	// 개별 데이터 요소의 크기
		int (cdecl *compare)(const void *, const void *) // 비교 함수에 대한 포인터
);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 함수 포인터는 바로 이 함수의 메모리 주소를 저장하는 변수

int ComparePoint (const void* _elem1, const void* _elem2)
{
	int* elem1 = (int*)_elem1; // 첫번째 매개변수를 정수 포인터 변수에 할당
	int* elem2 = (int*)_elem2; // 두번째 매개변수를 정수 포인터 변수에 할당
	
	if(*elem1 > *elem2)
		return 1;
	else if(*elem1 < *elem2)
		return -1;
	else
		return 0;
}

int main() {
	int DataSet[] = {6, 4, 2, 3, 1, 5};
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	
	qsort((void*)DataSet, Length, sizeof(int), &ComparePoint);
	
	for(int i=0; i<Length; i++)
		printf("%d ", DataSet[i]);
	
	printf("\n");
	
	return 0;
}