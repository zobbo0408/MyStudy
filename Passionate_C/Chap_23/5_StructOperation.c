#include<stdio.h>

typedef struct point{
	int xpos;
	int ypos;
}Point;

int main(){
	Point pos1 = {7, -5};
	Point pos2;
	pos2 = pos1;
	
	printf("크기 : %ld\n", sizeof(pos1));
	printf("[%d %d] \n", pos1.xpos, pos1.ypos);
	printf("크기 : %ld\n", sizeof(pos2));
	printf("[%d %d] \n", pos2.xpos, pos2.ypos);
	
	return 0;
}