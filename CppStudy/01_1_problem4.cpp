#include <iostream>

int CalSalary(int sales) {
	return (int)(50 + sales * 0.12);
}

int main(void) {
	
	while (true) {
		int sales;
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		std::cin >> sales;
		if (sales == -1) break;
		
		std::cout << "�̹� �� �޿�: " << CalSalary(sales) << "����"<< std::endl;
	}

	std::cout << "���α׷��� �����մϴ�.";
	return 0;

}