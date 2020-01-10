#define _CRT_SECURE_NO_WARNINGS
#include <iostream>	
#include <cstring>
using  namespace std;

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };
}

class NameCard {

private:
	char* name;
	char* company;
	char* phone;
	int position;

public:
	NameCard(char* name, char* company, char * phone, int position) : position(position) {
		this->name = new char[strlen(name) + 1];
		this->company = new char[strlen(company) + 1];
		this->phone = new char[strlen(phone) + 1];

		strcpy(this->name, name);
		strcpy(this->company, company);
		strcpy(this->phone, phone);
	}
	NameCard(NameCard &ref) : position(ref.position) {
		name = new char[strlen(ref.name) + 1];
		company = new char[strlen(ref.company) + 1];
		phone = new char[strlen(ref.phone) + 1];

		strcpy(name, ref.name);
		strcpy(company, ref.company);
		strcpy(phone, ref.phone);
	}
	~NameCard() {
		//�迭�ϰ�� delete �ڿ� [] �߰�
		delete[]name;
		delete[]company;
		delete[]phone;
	}
	void ShowNameCardInfo() const {
		cout << "�̸�:" << name << endl;
		cout << "ȸ��:" << company << endl;
		cout << "��ȭ��ȣ:" << phone << endl;
		cout << "����:";
		switch (position) {
		case COMP_POS::CLERK:
			cout << "���" << endl;
			break;
		case COMP_POS::SENIOR:
			cout << "����" << endl;
			break;
		case COMP_POS::ASSIST:
			cout << "�븮" << endl;
			break;
		case COMP_POS::MANAGER:
			cout << "����" << endl;
			break;
		default:
			break;
		}
		cout << endl;
	}
};

int main(void) {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}