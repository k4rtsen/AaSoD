#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define forn(i, n) for (size_t i = 0; i < static_cast<size_t>(n); i++)

int BinarySearch(int *, int, int, int);

typedef vector<int>::iterator int_iter;
// if we return int_iter, we dont check the existence of the element.
// but we can return the int -1 value if the element doesnt exist.
int_iter BS(int_iter start, int_iter end, int searchItem);

int main()
{
	ifstream ifs("D:\\karen\\dev\\cpp\\AaSoD\\read.txt");
	if (ifs.is_open())
	{
		int n{0};
		vector<int> arr;
		ifs >> n;
		forn(_, n)
		{
			int x{0};
			ifs >> x;
			arr.push_back(x);
		}

		int searcItem{0};
		ifs >> searcItem;
		
		clock_t start = clock();

		cout << BS(arr.begin(), arr.end(), searcItem) - arr.begin() << endl;

		clock_t end = clock();
		double seconds = (double)(end - start) / CLOCKS_PER_SEC;
		printf("The time: %f seconds\n", seconds);
	}
}

int BinarySearch(int *arr, int item, int start, int end)
{
	int mid = (end + start) / 2;
	if (end - start <= 1)
	{
		if (arr[end - start] != item)
			return -1;
		else
			return arr[end - start];
	}
	else
	{
		if (arr[mid] == item)
			return arr[mid];
		else
		{
			if (arr[mid] < item)
				BinarySearch(arr, item, mid, end);
			else
				BinarySearch(arr, item, start, mid);
		}
	}
}

int_iter BS(int_iter start, int_iter end, int searchItem)
{
	int_iter mid = (start + (end - start) / 2);
	if (*mid == searchItem)
		return mid;
	// else if ((end - start) == 1)
	// 	return -1;

	if (*mid > searchItem)
		return BS(start, mid, searchItem);
	else
		return BS(mid, end, searchItem);
}
