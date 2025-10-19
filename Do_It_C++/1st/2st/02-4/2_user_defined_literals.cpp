// 사용자 정의 리터럴로 거리 단위 변환하기
#include<iostream>
using namespace std;

const long double km_per_mile = 1.609344L;

long double operator"" _km(long double val){
	return val;
}

long double operator"" _mi(long double val){
	return val * km_per_mile;
}

int main(){
	long double distance1 = 1.0_km; // 킬로미터는 정상
	long double distance2 = 1.0_mi; // 마일은 킬로미터 단위로 변환해서 저장
	
	cout << distance1 + distance2 << "km" << endl;
	
	return 0;
}