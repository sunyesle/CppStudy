#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LENGTH=20;

void ShowMenu(void);
void CreateAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void PrintAllAcountInfo(void);

enum {
	CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
};

typedef struct {
	int accID;
	int balance;
	char cusName[NAME_LENGTH];
}Account;

Account accArr[100];
int accNum = 0;

int main(void) {
	int choice;

	while (1) {
		ShowMenu();
		cout << "���� : ";
		cin >> choice;

		switch (choice) {
		case CREATE: 
			CreateAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW: 
			WithdrawMoney();
			break;
		case INQUIRE:
			PrintAllAcountInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}

	}
}

void ShowMenu(void) {
	cout << "-----Menu-----" << endl;
	cout << "1.���°���" << endl;
	cout << "2.�Ա�" << endl;
	cout << "3.���" << endl;
	cout << "4.�������� ��ü ���" << endl;
	cout << "5.���α׷� ����" << endl;
}

void CreateAccount(void)
{
	int id;
	int balance;
	char name[NAME_LENGTH];

	cout << "[���°���]" << endl;
	cout << "����ID : " ; cin >> id;
	cout << "�̸� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	
	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy_s(accArr[accNum].cusName,name);
	accNum++;
}

void DepositMoney(void)
{
	int money;
	int id;

	cout << "[��   ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout <<"��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;

	cout << "[��   ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id) {
			accArr[i].balance -= money;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void PrintAllAcountInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "����ID : " << accArr[i].accID << endl;
		cout << "�̸� : " << accArr[i].cusName << endl;
		cout << "�ܾ� : " << accArr[i].balance << endl<<endl;
	}
}
