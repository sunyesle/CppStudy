#include <iostream> 

int main(void) {
	int num;
	std::cout << "구구단 몇단? ";
	std::cin >> num;

	for (int i = 1; i <= 9; i++)
	{
		std::cout << num << 'x' << i << '=' << num * i<<std::endl;
	}
	return 0;
}