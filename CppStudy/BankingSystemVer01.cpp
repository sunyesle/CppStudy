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
	cout << "계좌ID : " ; cin >> id;
	cout << "이름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;
	
	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy_s(accArr[accNum].cusName,name);
	accNum++;
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
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout <<"유효하지 않은 ID입니다." << endl << endl;
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
		if (accArr[i].accID == id) {
			accArr[i].balance -= money;
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;
}

void PrintAllAcountInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "계좌ID : " << accArr[i].accID << endl;
		cout << "이름 : " << accArr[i].cusName << endl;
		cout << "잔액 : " << accArr[i].balance << endl<<endl;
	}
}
