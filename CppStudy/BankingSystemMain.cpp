/*
 * ����Ʈ���� ����: Banking System Ver 0.7
 *
 * �����̸�: BankingSystemMain.cpp
 * ������Ʈ ����: [2020, 01, 14] ���Ϲ��� 0.7
 */

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void) {
	int choice;
	AccountHandler manager;

	while (1) {
		manager.ShowMenu();
		cout << "���� : ";
		cin >> choice;

		switch (choice) {
		case CREATE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.PrintAllAcountInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
	}
}