#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void main(void) {
	
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		cout << rand()% 100 << endl;
	}

}

