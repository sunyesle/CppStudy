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
	NameCard(char* n, char* c, char * p, int pos) : position(pos){
		name = new char[strlen(n) +1];
		strcpy(name, n);

		company = new char[strlen(c) + 1];
		strcpy(company, c);

		phone = new char[strlen(p) + 1];
		strcpy(phone, p);
	}
	~NameCard() {
		//�迭�ϰ�� delete �ڿ� [] �߰�
		delete []name;
		delete []company;
		delete []phone;
	}
	void ShowNameCardInfo() const {
		cout << "�̸�:" << name << endl;
		cout << "ȸ��:" << company << endl;
		cout << "��ȭ��ȣ:" << phone << endl;
		cout << "����:";
		switch (position) {
		case COMP_POS::CLERK :
			cout << "���"<< endl;
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