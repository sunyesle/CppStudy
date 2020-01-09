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
			cout << "�߸��� ������ ���޵Ǿ� �ǸŸ� ����մϴ�." << endl;
			return 0;
		}
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSaleResult() const {
		cout << "������� : " << numOfApples << endl;
		cout << "�Ǹż��� : " << myMoney << endl << endl;
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
			cout << "�߸��� ������ ���޵Ǿ� ���Ÿ� ����մϴ�." << endl;
			return;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowByResult() const {
		cout << "���� �ܾ� : " << myMoney << endl;
		cout << "��� ���� : " << numOfApples << endl << endl;
	}
};

int main(void) {
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSaleResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowByResult();
	return 0;
}