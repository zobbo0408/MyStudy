#include<stdio.h>

typedef struct point{
	int xpos;
	int ypos;
} Point;

typedef struct circle{
	double rad;
	Point cen;
} Circle;

void ShowCircleInfo(Circle * cptr){
	printf("[%d %d]\n", (cptr->cen).xpos, (cptr->cen).ypos);
	printf("radius : %g\n\n", cptr->rad);
}

int main(){
	Circle c1 = {3.5, {1, 2}};
	Circle c2 = {5.5, 2, 4};
	
	ShowCircleInfo(&c1);
	ShowCircleInfo(&c2);
	return 0;
}