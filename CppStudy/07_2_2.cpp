#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char * title;
	char * isbn;
	int price;
public:
	Book(char * title, char *isbn, int price)
		:price(price) {
		this->title = new char[strlen(title)+1];
		this->isbn = new char[strlen(isbn)+1];

		strcpy(this->title, title);
		strcpy(this->isbn, isbn);
	}
	void ShowBookInfo() {
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
};

class EBook : public Book {
private:
	char * DRMKey;
public:
	EBook(char * title, char *isbn, int price, char * DRMKey)
		: Book(title, isbn, price) {
		this->DRMKey = new char[strlen(DRMKey)+1];
		strcpy(this->DRMKey, DRMKey);
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}
};

int main(void) {
	Book book("���� C++", "555-12345-098-0", 15000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("���� C++ ebook", "555-12345-098-1", 10000, "afdkc9dsl01");
	ebook.ShowEBookInfo();
	return 0;
}