/*
 * �����̸�: Account.h
 * ������Ʈ ����: [2020, 01, 14] ���Ϲ��� 0.7
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