#include <iostream> 
#include <cstring>
using namespace std;

class BoundCheckIntArray {
private:
	int * arr;
	int arrlen;

	BoundCheckIntArray(const BoundCheckIntArray& arr) {}
	BoundCheckIntArray & operator=(const BoundCheckIntArray& arr) {}
public:
	BoundCheckIntArray(int len) : arrlen(len) {
		arr = new int[len];
	}
	int& operator[] (int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout<<"Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
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

class BoundCheck2DIntArray {
private:
	BoundCheckIntArray* *arr;
	int arrlen;

	BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) {}
	BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) {}
public:
	BoundCheck2DIntArray(int x, int y) : arrlen(x){
		arr = new BoundCheckIntArray*[arrlen];
		for (int i = 0; i < x; i++)
		{
			(arr[i]) = new BoundCheckIntArray(y);
		}
	}
	BoundCheckIntArray& operator[](int idx){
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		else {
			return *arr[idx];
		}
	}
	BoundCheckIntArray& operator[](int idx) const {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		else {
			return *arr[idx];
		}
	}
	int GetXLen() {
		return arrlen;
	}
	int GetYLen() {
		return arr[0]->GetArrayLen();
	}
};

void ShowAllData(const BoundCheckIntArray& ref) {
	int len = ref.GetArrayLen();
	for (int idx = 0; idx < len; idx++)
		cout << ref[idx] << endl;
}

int main(void) {

	BoundCheck2DIntArray arr(3, 4);
	for (int i = 0; i < arr.GetXLen(); i++)
	{
		for (int j = 0; j < arr.GetYLen(); j++)
		{
			arr[i][j] = i * arr.GetYLen() + j + 1;
		}
	}

	for (int i = 0; i < arr.GetXLen(); i++)
	{
		for (int j = 0; j < arr.GetYLen(); j++)
		{
			cout << arr[i][j]<< " ";
		}
		cout<< endl;
	}
	return 0;
}