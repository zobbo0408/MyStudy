#include<iostream>
#include<string>

using namespace std;

class bank{
	private:
	int safe;
	string bank_name;
	
	public:
	bank(string name) : bank_name(name){safe = 0;};
	~bank(){};
	void use_counter(int _in, int _out);
	void transfer_account(int safe);
	int get_safe(){return safe;};
	void reset_account();
	bank& deposit_interest(int interest);
	bank& withdraw_utility(int utility);
	bank& withdraw_tax(int tax);
	
	string get_bank_name(){return bank_name; };
};

void bank::use_counter(int _in, int _out){
	safe += _in;
	safe -= _out;
	cout << bank_name << " 입금 : " << _in << 
		", 출금 : " << _out << endl;
}

void bank::transfer_account(int safe){
	this->safe = safe;
	cout << bank_name << "으로 계좌 이동 : " << safe << endl;
}

void bank::reset_account(){
	this->safe = 0;
	cout << bank_name << " 계좌가 초기화되었습니다." << endl;
}

bank& bank::deposit_interest(int interest){
	safe += interest;
	cout << bank_name << " 이자 지급 : " << interest << endl;
	return *this;
}

bank& bank::withdraw_utility(int utility){
	safe -= utility;
	cout << bank_name << " 공과금 납부 : " << utility << endl;
	return *this;
}

bank& bank::withdraw_tax(int tax){
	safe -= tax;
	cout << bank_name << " 세금 납부 : " << tax << endl;
	return *this;
}

int main(){
	bank rich_bank("부유한 은행"), global_bank("세계적 은행");
	rich_bank.use_counter(50, 10);
	cout << endl;
	
	global_bank.transfer_account(rich_bank.get_safe());
	rich_bank.reset_account();
	cout << endl;
	
	//함수 체이닝 호출 - 함수가 차례로 호출됨
	global_bank.deposit_interest(10).withdraw_utility(1).withdraw_tax(2);
	cout << endl;
	cout << global_bank.get_bank_name() << "잔액 : " << global_bank.get_safe() << endl;
	return 0;
}