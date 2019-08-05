#include <iostream>

int main(void) {
	int val[5];
	int result=0;

	for (int i = 0; i < 5; i++)
	{
		std::cout << i+1<<"번째 정수입력: ";
		std::cin >> val[i];
		result += val[i];
	}
	
	std::cout << "합계: " << result << std::endl;
	return 0;
}