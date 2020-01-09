#include <iostream>
using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money) {
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money) {
		if (money < 0) {
			cout << "잘못된 정보가 전달되어 판매를 취소합니다." << endl;
			return 0;
		}
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSaleResult() const {
		cout << "남은사과 : " << numOfApples << endl;
		cout << "판매수익 : " << myMoney << endl << endl;
	}
};

class FruitBuyer {
	int myMoney;
	int numOfApples;
public:
	void InitMembers(int money) {
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money) {
		if (money < 0) {
			cout << "잘못된 정보가 전달되어 구매를 취소합니다." << endl;
			return;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowByResult() const {
		cout << "현재 잔액 : " << myMoney << endl;
		cout << "사과 개수 : " << numOfApples << endl << endl;
	}
};

int main(void) {
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSaleResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowByResult();
	return 0;
}