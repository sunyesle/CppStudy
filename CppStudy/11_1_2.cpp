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
	Book(Book & ref)
		:price(ref.price)
	{
		title = new char[strlen(ref.title)+1];
		isbn = new char[strlen(ref.isbn)+1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
	}
	Book& operator=(const Book & ref) {
		delete[] title;
		delete[] isbn;

		title = new char[strlen(ref.title)+1];
		isbn = new char[strlen(ref.isbn)+1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
		price = ref.price;
		return *this;
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book() {
		delete[] title;
		delete[] isbn;
		cout << "Book 소멸자" << endl;
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
	EBook(EBook& ref) 
		: Book(ref)
	{
		DRMKey = new char[strlen(ref.DRMKey)+1];
		strcpy(DRMKey, ref.DRMKey);
	}
	EBook& operator=(const EBook& ref) {
		Book::operator=(ref);
		delete[] DRMKey;
		DRMKey = new char[strlen(ref.DRMKey)+1];
		strcpy(this->DRMKey, ref.DRMKey);
		return *this;
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~EBook() {
		delete[] DRMKey;
		cout << "EBook 소멸자" << endl;
	}
};

int main(void) {
	
	EBook book1("좋은 C", "555-12345-098-0", 15000,"sddsdsdssd");
	EBook book2 = book1;
	book1.ShowBookInfo();
	book2.ShowBookInfo();
	
	cout << endl;

	EBook ebook1("좋은 C++", "555-12345-098-1", 10000, "afdkc9dsl01");
	EBook ebook2("test", "0000", 1, "asdf");
	ebook2 = ebook1;
	ebook1.ShowEBookInfo();
	ebook2.ShowEBookInfo();

	return 0;
}