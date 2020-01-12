//chapter08

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

enum { CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

enum { NORMAL=1, CREDIT = 2};

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
	virtual void Deposite(int money) {
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

class NormalAccount : public Account {
private:
	const int interestRate;
public:
	NormalAccount(int id, int bal, char* name, int interRate)
		: Account(id, bal, name), interestRate(interRate)
	{}
	virtual void Deposite(int money) {
		Account::Deposite(money);
		Account::Deposite(money * (interestRate/100.0));
	}
};

class HighCreditAccount : public NormalAccount {
private:
	const int creditRating;
public:
	HighCreditAccount(int id, int bal, char* name, int interRate, int credit)
		:NormalAccount(id, bal, name, interRate), creditRating(credit)
	{}
	virtual void Deposite(int money) {
		NormalAccount::Deposite(money);
		Account::Deposite(money*(creditRating/100.0));
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
protected:
	void MakeNormalAccount();
	void MakeHighCreditAccount();
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
	int choice;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���";
	cout << "����: "; cin >> choice;

	switch (choice)
	{
	case NORMAL:
		MakeNormalAccount();
		break;
	case CREDIT:
		MakeHighCreditAccount();
		break;
	default:
		break;
	}
}

void AccountHandler::MakeNormalAccount(void) {
	int id;
	int balance;
	char name[NAME_LENGTH];
	int interRate;
	
	cout << "[���뿹�ݰ��°���]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�̸� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	cout << "������: "; cin >> interRate;
	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeHighCreditAccount(void) {
	int id;
	int balance;
	char name[NAME_LENGTH];
	int interRate;
	int credit;

	cout << "[�ſ�ŷڰ��°���]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�̸� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> credit;

	switch (credit)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate,LEVEL_A );
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	default:
		break;
	}
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