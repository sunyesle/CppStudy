/*
 * �����̸�: Account.h
 * ������Ʈ ����: [2020, 01, 14] ���Ϲ��� 0.7
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account {
private:
	int accID;
	int balance;
	String cusName;
public:
	Account(int id, int bal, String name);
	Account(Account & ref);

	Account& operator=(const Account& ref);

	int GetAccID() const;
	virtual void Deposite(int money);
	void Withdraw(int money);
	void ShowAccountInfo() const;
	~Account();
};
#endif