#include<iostream>
#include<string>
#include<filesystem>
#include<fstream>

using namespace std;
namespace fs = std::filesystem;

int main(){
	fs::create_directories("/workspace/Study/Do_It_C++/3st/11st/11_3/my_forder");
	
	ofstream outFile("/workspace/Study/Do_It_C++/3st/11st/11_3/my_forder/_test.txt");
	
	if(outFile.is_open()) {
		outFile << "Park JoonYeong" << endl;
		outFile.close();
	}
	else {
		cerr << "can't open the file" << endl;
	}
	
	return 0;
	
}