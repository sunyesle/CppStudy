#include <iostream>

int main(void) {
	
	while (true) {
		int num;
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		std::cin >> num;
		if (num == -1) break;
		
		int result = 50 + num * 0.12;
		std::cout << "�̹� �� �޿�: " << result << "����"<< std::endl;
	}

	std::cout << "���α׷��� �����մϴ�.";
	return 0;
}