#include <iostream>

int main(void) {
	
	while (true) {
		int num;
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin >> num;
		if (num == -1) break;
		
		int result = 50 + num * 0.12;
		std::cout << "이번 달 급여: " << result << "만원"<< std::endl;
	}

	std::cout << "프로그램을 종료합니다.";
	return 0;
}