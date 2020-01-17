/*
 * �����̸�: AccountHandler.h
 * ������Ʈ ����: [2020, 01, 14] ���Ϲ��� 0.7
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler {
private:
	BoundCheckAccountPtrArray accArr;
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

#endif