#include<iostream>
#include<string>
using namespace std;

void from_cat_to_dog(string& str) {
	int pos, replaced_size;
	string find_str("고양이");
	string replace_str("강아지");
	replaced_size = find_str.length();
	
	while((pos = str.find("고양이")) != string::npos){
		str.replace(pos, replaced_size, replace_str);
		pos += replaced_size;
	}
}

int main(){
	string str = "나는 고양이, 고양이, 고양이";
	
	cout << str << endl;
	from_cat_to_dog(str);
	
	cout << str << endl;
	return 0;
}