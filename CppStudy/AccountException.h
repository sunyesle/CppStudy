#ifndef __Account_Exception__
#define __Account_Exception__

#include <iostream>
using namespace std;


class AccountException
{
public:
	virtual void ShowException() = 0; //���� �����Լ�
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
		cout << money << "�� �ԱݺҰ�" << endl;
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
		cout << "�ܾ��� �����մϴ�." << endl;
		cout << "��ݱݾ�:" <<money<<" �����ܾ�:" << balance << endl;
	}
};

#endif // !__Account_Exception__
