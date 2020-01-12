#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo {
private:
	char *name;
	int age;
public:
	MyFriendInfo(char *name, int age) : age(age)
	{
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
		cout << "MyFriendInfo 생성자" << endl;
	}
	void ShowMyFriendInfo() {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~MyFriendInfo() {
		delete[] name;
		cout << "MyFriendInfo 소멸자" << endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char * addr;
	char * phone;
public:
	MyFriendDetailInfo(char *name, int age, char *addr, char *phone)
		: MyFriendInfo(name, age) {
		this->addr = new char[strlen(addr)+1];
		this->phone = new char[strlen(phone)+1];

		strcpy(this->addr, addr);
		strcpy(this->phone, phone);
		cout << "MyFriendDetailInfo 생성자" << endl;
	}
	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}
	~MyFriendDetailInfo() {
		delete[] addr;
		delete[] phone;
		cout << "MyFriendDetailInfo 소멸자" << endl;
	}
};

int main(void) {
	MyFriendDetailInfo myFriend("가나다", 20, "---", "010-0000-0000");
	myFriend.ShowMyFriendDetailInfo();
	return 0;
}

