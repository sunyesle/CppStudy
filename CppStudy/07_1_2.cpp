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
		cout << "MyFriendInfo ������" << endl;
	}
	void ShowMyFriendInfo() {
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~MyFriendInfo() {
		delete[] name;
		cout << "MyFriendInfo �Ҹ���" << endl;
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
		cout << "MyFriendDetailInfo ������" << endl;
	}
	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl << endl;
	}
	~MyFriendDetailInfo() {
		delete[] addr;
		delete[] phone;
		cout << "MyFriendDetailInfo �Ҹ���" << endl;
	}
};

int main(void) {
	MyFriendDetailInfo myFriend("������", 20, "---", "010-0000-0000");
	myFriend.ShowMyFriendDetailInfo();
	return 0;
}

