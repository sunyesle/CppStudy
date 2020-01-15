#include <iostream> 
#include <cstring>
using namespace std;

class BoundCheck2DIntArray {
private:
	int * arr;
	int arrlen;

	// 안전성을 높익 위해 복사와 대입을 원천적으로 막음 p.459
	BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) {}
	BoundCheck2DIntArray & operator=(const BoundCheck2DIntArray& arr) {}
public:
	BoundCheck2DIntArray(int len) : arrlen(len) {
		arr = new int[len];
	}
	int& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout<<"Array index out of bound exception" << endl;
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
	~BoundCheck2DIntArray() {
		delete[]arr;
	}
};

void ShowAllData(const BoundCheck2DIntArray& ref) {
	int len = ref.GetArrayLen();
	for (int idx = 0; idx < len; idx++)
		cout << ref[idx] << endl;
}

int main(void) {
	BoundCheck2DIntArray arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;;
	ShowAllData(arr);
	return 0;
}