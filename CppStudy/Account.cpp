/*
 * 파일이름: Account.cpp
 * 업데이트 정보: [2020, 01, 14] 파일버전 0.7
 */

#include "Account.h"
#include "BankingCommonDecl.h"
#include "AccountException.h"

Account::Account(int id, int bal, String name) : accID(id), balance(bal),cusName(name) { }

Account::Account(Account & ref) : accID(ref.accID), balance(ref.balance), cusName(ref.cusName) { }

int Account::GetAccID() const {
	return accID;
}

void Account::Deposite(int money)  {
	if (money < 0) {
		throw MinusException(money);
}
	balance += money;
}

void Account::Withdraw(int money) {
	if (money < 0)
	{
		throw MinusException(money);
	}
	if (money > balance) {
		throw WithdrawException(balance, money);
	}
	balance -= money;
}

void Account::ShowAccountInfo() const {
	cout << endl;
	cout << "계좌ID : " << this->accID << endl;
	cout << "이름 : " << this->cusName << endl;
	cout << "잔액 : " << this->balance << endl;
}

Account::~Account() { }

Account & Account::operator=(const Account & ref)
{
	accID = ref.accID;
	cusName =ref.cusName;
	balance = ref.balance;
	return *this;
}
