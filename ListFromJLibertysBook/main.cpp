#include "Node.h"

int main() {
	Data* pData;
	int val;
	LinkedList list;

	for (;;) {
		cout << "What is value? (0 for exit)\n";
		cin >> val;
		if (!val)
			break;
		pData = new Data(val);
		list.Insert(pData);
	}

	list.ShowAll();
	system("pause");
}