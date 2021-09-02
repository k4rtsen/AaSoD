#include <iostream>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

int BinarySearch(int*, int, int, int);

int main() {
	
	int len = 0;
	int item = 0;
	cin >> len;
	cin >> item;
	int* mas = new int[len];
	for (int i = 0; i < len; i++)
		mas[i] = i + 1;
	
	cout << BinarySearch(mas, item, 0, len-1) << endl;

	delete[] mas;
	system("pause");
}

int BinarySearch(int *arr, int item, int start, int end)
{
	int mid = (end + start) / 2;
	if (end - start <= 1) {
		if (arr[end - start] != item) return -1;
		else return arr[end - start];
	}
	else {
		if (arr[mid] == item) return arr[mid];
		else {
			if (arr[mid] < item) BinarySearch(arr, item, mid, end);
			else BinarySearch(arr, item, start, mid);
		}
	}
}
