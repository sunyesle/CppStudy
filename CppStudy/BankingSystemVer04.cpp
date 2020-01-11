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
	Account(Account & ref) : accID(ref.accID), balance(ref.balance){
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
		cout << "계좌ID : " << this->accID << endl;
		cout << "이름 : " << this->cusName << endl;
		cout << "잔액 : " << this->balance << endl << endl;
	}
	~Account() {
		delete[] cusName;
	}
};

void ShowMenu(void);
void CreateAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void PrintAllAcountInfo(void);

Account * accArr[100];
int accNum = 0;

int main(void) {
	int choice;

	while (1) {
		ShowMenu();
		cout << "선택 : ";
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
			cout << "잘못된 입력입니다." << endl;
			break;
		}

	}
}

void ShowMenu(void) {
	cout << "-----Menu-----" << endl;
	cout << "1.계좌개설" << endl;
	cout << "2.입금" << endl;
	cout << "3.출금" << endl;
	cout << "4.계좌정보 전체 출력" << endl;
	cout << "5.프로그램 종료" << endl;
}

void CreateAccount(void)
{
	int id;
	int balance;
	char name[NAME_LENGTH];

	cout << "[계좌개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "이름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void)
{
	int money;
	int id;

	cout << "[입   금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "입금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposite(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;
}

void WithdrawMoney(void)
{
	int money;
	int id;

	cout << "[출   금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id) {
			if (!accArr[i]->Withdraw(money)) {
				cout << "잔액이 부족합니다." << endl;
				return;
			}
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;
}

void PrintAllAcountInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccountInfo();
		cout << endl;
	}
}
