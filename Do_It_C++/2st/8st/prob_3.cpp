#include<iostream>
#include<vector>
using namespace std;

class coffee_shop {
	public:
	void order_coffee();
	void set_name(string shop_name) { name = shop_name; };
	string get_name() { return name; };
	
	protected:
	string name;
	virtual void receiving_order() = 0;
	virtual void making_coffee() = 0;
	virtual void serving() = 0;
};

void coffee_shop::order_coffee(){
	receiving_order();
	making_coffee();
	serving();
}

class self_serving : public coffee_shop {
	protected :
	virtual void receiving_order() override {
		cout << "키오스크로 주문 받기" << endl;
	};
	virtual void making_coffee() override {
		cout << "기계에서 자동으로 만들기" << endl;
	};
	virtual void serving() override {
		cout << "기계에서 꺼내가기" << endl;
	};
};

class franchise : public coffee_shop {
	protected:
	virtual void receiving_order() override {
    	cout << "점원이 직접 주문 받기" << endl;
  	};
  	virtual void making_coffee() override {
		cout << "바리스타의 커피 만들기" << endl;
  	};
  	virtual void serving() override {
    	cout << "이름 부르면서 커피 전달하기" << endl;
  	};
};

class small_shop : public coffee_shop {
protected:
  	virtual void receiving_order() override {
    	cout << "자리에서 커피 주문 받기" << endl;
  	};
  	virtual void making_coffee() override {
    	cout << "카페 주인이 직접 커피 내리기" << endl;
  	};
  	virtual void serving() override {
    	cout << "자리로 커피 가져다 주기" << endl;
  	};
};

int main(){
	self_serving self_serving_shop;
	franchise franchise_shop;
	small_shop small_shop;
	vector<coffee_shop*> coffee_shop_list;
	
	self_serving_shop.set_name("무인매장");
	coffee_shop_list.push_back(&self_serving_shop);
	
	franchise_shop.set_name("프랜차이즈");
	coffee_shop_list.push_back(&franchise_shop);
	
	small_shop.set_name("로컬 커피");
	coffee_shop_list.push_back(&small_shop);
	
	for(auto&& item : coffee_shop_list){
		cout << endl << ">> " << item->get_name() << " << " << endl;
		item->order_coffee();
	}
	
	return 0;
}