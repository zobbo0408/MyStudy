#include<stdio.h>

#define PI 3.14
#define PRODUCT(X, Y) ((X)*(Y))
#define CIRCLE_AREA(R) (PRODUCT((R), (R)) * PI)

int main(){
	double rad = 2.1;
	printf("반지름 %lf의 원의 넓이 : %lf\n", rad, CIRCLE_AREA(rad));
	
	return 0;
}