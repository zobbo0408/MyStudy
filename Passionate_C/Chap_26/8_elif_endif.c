#include<stdio.h>

#define HIT_NUM 7

int main(){
#if HIT_NUM == 6
	puts("매크로 상수 HIT_NUM은 현재 6입니다.");
#elif HIT_NUM == 7
	puts("매크로 상수 HIT_NUM은 현재 7입니다.");
#else
	puts("매크로 상수 HIT_NUM은 6,7 모두 아닙니다.");
#endif
	return 0;
}