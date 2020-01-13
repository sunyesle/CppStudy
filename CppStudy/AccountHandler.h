/*
 * 파일이름: AccountHandler.h
 * 업데이트 정보: [2020, 01, 14] 파일버전 0.7
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

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

#endif