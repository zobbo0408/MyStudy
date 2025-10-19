#include<stdio.h>

int main(){
	char name[20];
	char sex;
	int age;
	
	FILE * fp = fopen("friend.txt", "wt");
	
	for(int i = 0; i<3; i++){
		printf("이름 성별 나이 순으로 입력 : ");
		scanf("%s %c %d", name, &sex, &age);
		getchar(); // 버퍼에 남아있는 \n의 소멸을 위해서
		fprintf(fp, "%s %c %d", name, sex, age);
	}
	
	fclose(fp);
	
	return 0;ㅅ
}