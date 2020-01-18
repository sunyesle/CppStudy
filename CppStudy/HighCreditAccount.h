/*
 * 파일이름: HighCreditAccount.h
 * 업데이트 정보: [2020, 01, 14] 파일버전 0.7
 */

#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
private:
	const int creditRating;
public:
	HighCreditAccount(int id, int bal, String name, int interRate, int credit)
		:NormalAccount(id, bal, name, interRate), creditRating(credit)
	{}
	virtual void Deposite(int money) {
		NormalAccount::Deposite(money);
		Account::Deposite(money*(creditRating / 100.0));
	}
};

#endif