#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	srand(time(NULL));

	List<int> list;
	int N; // size of list
	cout << "Enter the size of list... ";
	try
	{
		cin >> N;
		if (N < 0)
			throw exception{ "Error! Size can't be negative." };
	}
	catch (const std::exception& e)
	{
		printf("Main exception caught with message: %s\n", e.what());
		N = 5;
	}

	for (size_t i = 0; i < N; i++) {
		list.push_back(rand() % 10);
	}
	list.print();

	//cout << "Deleted item: " << list.pop_front() << endl;
	cout << "Adding process..." << endl;
	list.insert(99, 4);
	list.print();

	cout << "Removing process..." << endl;
	list.removeAt(4);
	list.print();

	return 0;
}
