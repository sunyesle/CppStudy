#include <iostream> 
#include <cstring>
using namespace std;

class BoundCheckIntArray {
private:
	int * arr;
	int arrlen;

	// 안전성을 높이기 위해 복사와 대입을 원천적으로 막음 p.459
	BoundCheckIntArray(const BoundCheckIntArray& arr) {}
	BoundCheckIntArray & operator=(const BoundCheckIntArray& arr) {}
public:
	BoundCheckIntArray(int len) : arrlen(len) {
		arr = new int[len];
	}
	int& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	// const 선언 여부도 함수 오버로딩의 조건에 포함됨
	int operator[] (int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrayLen() const { return arrlen; }
	~BoundCheckIntArray() {
		delete[]arr;
	}
};

void ShowAllData(const BoundCheckIntArray& ref) {
	int len = ref.GetArrayLen();
	for (int idx = 0; idx < len; idx++)
		cout << ref[idx] << endl;
}

int main(void) {
	BoundCheckIntArray arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;;
	ShowAllData(arr);
	return 0;
}