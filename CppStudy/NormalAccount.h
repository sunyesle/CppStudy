/*
 * �����̸�: NormalAccount.h
 * ������Ʈ ����: [2020, 01, 14] ���Ϲ��� 0.7
 */

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account {
private:
	const int interestRate;
public:
	NormalAccount(int id, int bal, char* name, int interRate)
		: Account(id, bal, name), interestRate(interRate)
	{}
	virtual void Deposite(int money) {
		Account::Deposite(money);
		Account::Deposite(money * (interestRate / 100.0));
	}
};

#endif