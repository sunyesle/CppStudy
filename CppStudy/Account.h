/*
 * 파일이름: Account.h
 * 업데이트 정보: [2020, 01, 14] 파일버전 0.7
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	int accID;
	int balance;
	char * cusName;
public:
	Account(int id, int bal, char* name);
	Account(Account & ref);

	Account& operator=(const Account& ref);

	int GetAccID() const;
	virtual void Deposite(int money);
	bool Withdraw(int money);
	void ShowAccountInfo() const;
	~Account();
};
#endif