#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <cstring>
using namespace std;

class DepositException 
{
private:
	int money;
public:
	DepositException(int money) : money(money)
	{}
	void ShowException()
	{
		cout <<"[예외 메시지: " << money << "는 입금불가]" << endl;
	}
};

class WithdrawException
{
private:
	int balance;
public:
	WithdrawException(int money) : balance(money)
	{}
	void ShowException()
	{
		cout << "[예외 메시지: 잔액 " << balance << ", 잔액부족]" << endl;
	}
};

class Account
{
private:
	char accNum[50];
	int balance;
public:
	Account(char * acc, int money)
	{
		strcpy(accNum, acc);
	}
	void Deposit(int money) throw(DepositException)
	{
		if (money < 0)
		{
			DepositException expn(money);
			throw expn;
		}
		balance += money;
	}
	void Withdraw(int money) throw (WithdrawException)
	{
		if (money > balance)
			throw WithdrawException(balance);
		balance -= money;
	}
	void ShowMyMoney()
	{
		cout << "잔고: " << balance << endl << endl;
	}
};

int main(void)
{
	Account myAcc("12345-67890", 5000);

	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	catch (DepositException & expn)
	{
		expn.ShowException();
	}
	myAcc.ShowMyMoney();

	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch (WithdrawException & expn)
	{
		expn.ShowException();
	}
	myAcc.ShowMyMoney();
	return 0;
}