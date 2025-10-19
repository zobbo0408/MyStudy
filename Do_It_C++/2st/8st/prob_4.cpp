#include<iostream>
#include<vector>
using namespace std;

const int diff_height = 10;

class flight_controller {
	public:
	virtual int take_off();
	virtual int landing();
	virtual int ascend(int height, int delta);
	virtual int descend(int height, int delta);
};

int flight_controller::take_off() {
	cout << "이륙" << endl;
	return 100;
}

int flight_controller::landing() {
	cout << "착륙" << endl;
	return 100;
}

int flight_controller::ascend(int height, int delta) {
	cout << "꼬리 날개 작동 : 고도 상승 (" << height << " -> " << height + delta << ")" << endl;
	return height + delta;
}

int flight_controller::descend(int height, int delta) {
	int new_height = (height - delta) > 0 ? (height - delta) : 0 ;
	cout << "꼬리 날개 작동 : 고도 하강 (" << height << " -> " << new_height << ")" << endl;
	return new_height;
}

class horizental_controller : public flight_controller {
	public :
	virtual int ascend(int height, int delta) override;
	virtual int descend(int height, int delta) override;
};

int horizental_controller::ascend(int height, int delta) {
	cout << "양력 추가 : 고도 상승 (" << height << " -> " << height + delta << ")" << endl;
	return height + delta;
}

int horizental_controller::descend(int height, int delta) {
	int new_height = (height - delta) > 0 ? (height - delta) : 0 ;
	cout << "양력 감소 : 고도 하강 (" << height << " -> " << new_height << ")" << endl;
	return new_height;
}

class without_engine : public flight_controller {
	public :
	virtual int take_off() override;
	virtual int ascend(int height, int delta) override;
	virtual int descend(int height, int delta) override;
};

int without_engine::take_off(){
	cout << "높은 곳에서 출발" << endl;
	return 150;
}

int without_engine::ascend(int height, int delta){
	cout << "바람타고 상승 (" << height << " -> " << height + delta << ")" << endl;
	return height + delta;
}

int without_engine::descend(int height, int delta) {
	int new_height = (height - delta) > 0 ? (height - delta) : 0 ;
	cout << "동체 하강 (" << height << " -> " << new_height << ")" << endl;
	return new_height;
}

class emergency_controller {
	public :
	virtual void emergency_landing();
};

void emergency_controller::emergency_landing() {
	cout << "동체 착륙" << endl;
}

class escape : public emergency_controller {
	public:
	virtual void emergency_landing() override;
};

void escape::emergency_landing() {
	cout << "비상 탈출" << endl;
}

class flight_object {
	public :
	virtual void set_component(flight_controller* controller_param, emergency_controller* emergency_param) = 0;
	virtual void take_off() = 0;
	virtual void landing() = 0;
	virtual int ascend(int height) = 0;
	virtual int descend(int height) = 0;
	virtual void emergency_landing() = 0;
	
	protected :
	flight_controller* controller = nullptr;
	emergency_controller* emergency = nullptr;
	int flight_height = 0;
};

class flight_common : public flight_object {
	public :
	flight_common(string flight_name, flight_controller* controller_param, emergency_controller* emergency_param) 
		: object_name(flight_name){
			set_component(controller_param, emergency_param);
		};
	string get_object_name() { return object_name; };
	int get_height(){ return flight_height; };
	virtual void set_component(flight_controller* controller_param, emergency_controller* emergency_param) override;
	virtual void take_off() override;
	virtual void landing() override;
	virtual int ascend(int height) override;
	virtual int descend(int height) override;
	virtual void emergency_landing() override;
	
	private :
	string object_name;
};

void flight_common::set_component(flight_controller* controller_param, emergency_controller* emergency_param) {
	controller = controller_param;
	emergency = emergency_param;
}

void flight_common::take_off(){
	if(nullptr == controller){
		return;
	}
	flight_height = controller->take_off();
}

void flight_common::landing(){
	if(nullptr == controller) {
		return ;
	}
	flight_height = controller->landing();
}

int flight_common::ascend(int height) {
	if(nullptr == controller){
		return -1;
	}
	flight_height = controller->ascend(flight_height, height);
}

int flight_common::descend(int height) {
	if(nullptr == controller){
		return -1;
	}
	flight_height = controller->ascend(flight_height, height);
}

void flight_common::emergency_landing(){
	if(nullptr == emergency) {
		return ;
	}
	emergency->emergency_landing();
	flight_height = 0;
}

int main(){
	flight_controller aircraft_controller;
	horizental_controller helicopter_controller;
	without_engine glider_controller;
	
	emergency_controller emergency_device;
	escape emergency_exit;
	
	vector<flight_common*> flight_set;
	
	flight_common fighter("전투기", &aircraft_controller, &emergency_device);
	flight_set.push_back(&fighter);
	
	flight_common huge_aircraft("대형 항공기", &aircraft_controller, &emergency_device);
	flight_set.push_back(&huge_aircraft);
	
	flight_common helicopter("헬리콥터", &helicopter_controller, &emergency_exit);
	flight_set.push_back(&helicopter);
	
	flight_common hang_glider("행글라이더", &glider_controller, &emergency_exit);
	flight_set.push_back(&hang_glider);
	
	for(auto && flight : flight_set){
		cout << endl << flight->get_object_name() << "의 비행이 시작됩니다." << endl;
		cout << "이륙" << endl;
		flight->take_off();
		cout << "고도(" << flight->get_height() << ")" << endl;
		flight->ascend(30);
		cout << "고도(" << flight->get_height() << ")" << endl;
		flight->descend(10);
		cout << "고도(" << flight->get_height() << ")" << endl;
		flight->landing();
		cout << "고도(" << flight->get_height() << ")" << endl;
	}
	
	for (auto&& flight : flight_set) {
    	cout << endl << flight->get_object_name() << "의 비행이 시작됩니다." << endl;
    	cout << "이륙" << endl;
    	flight->emergency_landing();
  }
	
	return 0;
}