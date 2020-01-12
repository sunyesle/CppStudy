//chapter05, 06

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

enum {
	CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
};
const int NAME_LENGTH = 20;

class Account {
private:
	int accID;
	int balance;
	char * cusName;
public:
	Account() {}
	Account(int id, int bal, char* name) : accID(id), balance(bal) {
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}
	Account(Account & ref) : accID(ref.accID), balance(ref.balance) {
		cusName = new char[strlen(ref.cusName) + 1];
		strcpy(cusName, ref.cusName);
	}
	int GetAccID() const {
		return accID;
	}
	void Deposite(int money) {
		balance += money;
	}
	bool Withdraw(int money) {
		if (money > balance) {
			return false;
		}
		balance -= money;
		return true;
	}
	void ShowAccountInfo() const {
		cout << endl;
		cout << "����ID : " << this->accID << endl;
		cout << "�̸� : " << this->cusName << endl;
		cout << "�ܾ� : " << this->balance << endl;
	}
	~Account() {
		delete[] cusName;
	}
};

class AccountHandler {
private:
	Account * accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void);
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void PrintAllAcountInfo(void);
	~AccountHandler();
};

AccountHandler::AccountHandler()
	:accNum(0)
{
}

void AccountHandler::ShowMenu(void) {
	cout << "-----Menu-----" << endl;
	cout << "1.���°���" << endl;
	cout << "2.�Ա�" << endl;
	cout << "3.���" << endl;
	cout << "4.�������� ��ü ���" << endl;
	cout << "5.���α׷� ����" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int id;
	int balance;
	char name[NAME_LENGTH];

	cout << "[���°���]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�̸� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;

	accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;

	cout << "[��   ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposite(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;

	cout << "[��   ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id) {
			if (!accArr[i]->Withdraw(money)) {
				cout << "�ܾ��� �����մϴ�." << endl;
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

void AccountHandler::PrintAllAcountInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccountInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}

int main(void) {
	int choice;
	AccountHandler manager;

	while (1) {
		manager.ShowMenu();
		cout << "���� : ";
		cin >> choice;

		switch (choice) {
		case CREATE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.PrintAllAcountInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}

	}
}