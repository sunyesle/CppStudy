/*
 * �����̸�: Account.cpp
 * ������Ʈ ����: [2020, 01, 14] ���Ϲ��� 0.7
 */

#include "Account.h"
#include "BankingCommonDecl.h"

Account::Account(int id, int bal, char* name) : accID(id), balance(bal) {
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(Account & ref) : accID(ref.accID), balance(ref.balance) {
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

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

Account::~Account() {
	delete[] cusName;
}