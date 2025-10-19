#include<iostream>
using namespace std;

//int main(){
//	for(int i = 0; i < 5; i++){
	//	cout << "count : " << i << endl;
	//}
	
	//return 0;
//}

int main(){
	for(int i=0; i<5; i++){
		for(int k=4-i; k>0; k--){
			cout << " ";
		}
		for(int j=2*i+1; j>0; j--){
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}