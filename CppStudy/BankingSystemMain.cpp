/*
 * 소프트웨어 버전: Banking System Ver 0.7
 *
 * 파일이름: BankingSystemMain.cpp
 * 업데이트 정보: [2020, 01, 14] 파일버전 0.7
 */

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void) {
	int choice;
	AccountHandler manager;

	while (1) {
		manager.ShowMenu();
		cout << "선택 : ";
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
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
}