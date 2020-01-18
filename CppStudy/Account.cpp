/*
 * �����̸�: Account.cpp
 * ������Ʈ ����: [2020, 01, 14] ���Ϲ��� 0.7
 */

#include "Account.h"
#include "BankingCommonDecl.h"

Account::Account(int id, int bal, String name) : accID(id), balance(bal),cusName(name) { }

Account::Account(Account & ref) : accID(ref.accID), balance(ref.balance), cusName(ref.cusName) { }

int Account::GetAccID() const {
	return accID;
}

void Account::Deposite(int money) {
	balance += money;
}

bool Account::Withdraw(int money) {
	if (money > balance) {
		return false;
	}
	balance -= money;
	return true;
}

void Account::ShowAccountInfo() const {
	cout << endl;
	cout << "����ID : " << this->accID << endl;
	cout << "�̸� : " << this->cusName << endl;
	cout << "�ܾ� : " << this->balance << endl;
}

Account::~Account() { }

Account & Account::operator=(const Account & ref)
{
	accID = ref.accID;
	cusName =ref.cusName;
	balance = ref.balance;
	return *this;
}
