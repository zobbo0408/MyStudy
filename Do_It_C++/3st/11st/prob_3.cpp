#include<iostream>
#include<fstream>
#include<filesystem>
#include<vector>

using namespace std;
namespace fs = std::filesystem;

int main(){
	// 디렉터리 경로 설정
	fs::path dir_path = "my_forder";
	
	// 디렉터리 내 모든 파일 목록을 벡터에 저장
	vector<fs::path> files;
	for(const fs::directory_entry& entry : fs::directory_iterator(dir_path)) {
		if (entry.is_regular_file() && entry.path().extension() == ".txt") {
			files.push_back(entry.path());
		}
	}
	
	// 각 파일의 이름과 크기 출력
	for (std::vector<fs::path>::iterator it = files.begin(); it != files.end(); it++) {
		fs::path file = *it;
		std::uintmax_t file_size = fs::file_size(file);
		cout << "파일 이름: " << file.filename() << endl;
    	cout << "파일 크기: " << file_size << " 바이트" << endl << endl;
	}
	
	return 0;
}