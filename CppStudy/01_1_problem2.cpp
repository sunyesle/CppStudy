#include <iostream>

int main(void) {
	char name[100];
	char phone[100];

	std::cout << "이름: ";
	std::cin >> name;
	std::cout << "전화번호: ";
	std::cin >> phone;

	std::cout << "\n이름: " << name<<std::endl;
	std::cout << "전화번호: " << phone << std::endl;
	return 0;
}