#ifndef __Account_Exception__
#define __Account_Exception__

#include <iostream>
using namespace std;


class AccountException
{
public:
	virtual void ShowException() = 0; //순수 가상함수
};

class MinusException : public AccountException
{
private:
	int money;
public:
	MinusException(int money) : money(money)
	{}
	virtual void ShowException() override
	{
		cout << money << "는 입금불가" << endl;
	}
};

class WithdrawException : public AccountException
{
private:
	int balance;
	int money;
public:
	WithdrawException(int balance, int money) : balance(balance), money(money)
	{}
	virtual void ShowException() override
	{
		cout << "잔액이 부족합니다." << endl;
		cout << "출금금액:" <<money<<" 현재잔액:" << balance << endl;
	}
};

#endif // !__Account_Exception__
